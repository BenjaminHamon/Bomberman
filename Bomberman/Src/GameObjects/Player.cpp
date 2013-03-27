#include <Bomberman/Src/GameObjects/Player.h>

#include <Bomberman/Src/AppException.h>
#include <Bomberman/Src/GameObjects/Item.h>
#include <Bomberman/Src/GameObjects/Map.h>
#include <Bomberman/Src/Graphics/AssetManager.h>
#include <Bomberman/Src/Input/Input.h>
#include <Bomberman/Src/Input/InputBindings.h>
#include <Bomberman/Src/Main/Game.h>
#include <Bomberman/Src/Rectangle.h>

namespace Bomberman
{
	const float Player::BaseSpeed = 6.0f;
	const int Player::BombReloadTime = 30;

	Player::Player(const AssetManager& assets, int playerNumber, float xPosition, float yPosition, InputBindings* bindings)
		: GameObject(Rectangle(xPosition, yPosition, 48, 48), 1),
		  graphics_(assets, playerNumber, 2),
		  isMoving_(false),
		  speedModifier_(1.0f),
		  maxBombs_(1),
		  availableBombs_(1),
		  bombReload_(0),
		  power_(1),
		  direction_(MoveDirection::Down),
		  bindings_(bindings)
	{
	}

	Player::~Player(void)
	{
		if (bindings_ != nullptr)
			delete bindings_;
	}

	void Player::Update(const Input& input, Game& game, const Map& map, std::list<GameObject*>& objects)
	{
		Move(input, map, objects);
		PickItems(objects);

		if (input.IsKeyDown(bindings_->GetBinding(PlayerAction::DropBomb)))
		{
			if (availableBombs_ > 0)
			{
				bool result = game.CreateBomb(position_.X, position_.Y, power_);
				if (result == true)
					availableBombs_--;
			}
		}

		if (availableBombs_ < maxBombs_)
		{
			bombReload_++;
			if (bombReload_ >= BombReloadTime)
			{
				availableBombs_++;
				bombReload_ = 0;
			}
		}
	}

	void Player::Render(GraphicsManager& graphicsManager)
	{
		graphics_.Render(graphicsManager, static_cast<int>(position_.X), static_cast<int>(position_.Y), isMoving_, direction_);
	}

	void Player::Accept(GameObjectVisitor& visitor)
	{
		visitor.Visit(this);
	}

	void Player::Move(const Input& input, const Map& map, const std::list<GameObject*>& objects)
	{
		float xMove = 0;
		float yMove = 0;

		// This method first calculates the player attempted move (xMove and yMove).
		float realSpeed = RealSpeed();
		if (input.IsKeyDown(bindings_->GetBinding(PlayerAction::MoveUp)))
			yMove -= realSpeed;
		if (input.IsKeyDown(bindings_->GetBinding(PlayerAction::MoveLeft)))
			xMove -= realSpeed;
		if (input.IsKeyDown(bindings_->GetBinding(PlayerAction::MoveDown)))
			yMove += realSpeed;
		if (input.IsKeyDown(bindings_->GetBinding(PlayerAction::MoveRight)))
			xMove += realSpeed;
		
		Rectangle newPosition(position_);
		float xMoveUnit = (xMove == 0) ? 0 : xMove / abs(xMove);
		float yMoveUnit = (yMove == 0) ? 0 : yMove / abs(yMove);
		
		bool canMove = true;
		// Then we try to move there by going 1 point by 1 point.
		// We loop while the previous iteration made us move.
		// We try to move on each axis by 1 point as long as we have 'move points' (stored in xMove and yMove) for this axis.
		while(canMove == true)
		{
			canMove = false;
			if ((xMove * xMoveUnit) > 0) // Test if xMove and xMoveUnit have the same sign, if false xMove has changed sign during the last iteration.
			{
				newPosition.X += xMoveUnit;
				if (map.CanMoveTo(this, newPosition, objects))
				{
					xMove -= xMoveUnit;
					canMove = true;
				}
				else
				{
					newPosition.X -= xMoveUnit;
				}
			}
			if ((yMove * yMoveUnit) > 0)
			{
				newPosition.Y += yMoveUnit;
				if (map.CanMoveTo(this, newPosition, objects))
				{
					yMove -= yMoveUnit;
					canMove = true;
				}
				else
				{
					newPosition.Y -= yMoveUnit;
				}
			}
		} // At the end of the loop, we reached the closest point to the desired arrival.
		
		// Finally, we simply store the move direction and the new position.
		float xDiff = newPosition.X - position_.X;
		float yDiff = newPosition.Y - position_.Y;

		isMoving_ = (xDiff != 0) || (yDiff != 0);
		if (xDiff < 0)
			direction_ = MoveDirection::Left;
		else if (xDiff > 0)
			direction_ = MoveDirection::Right;
		if (yDiff < 0)
			direction_ = MoveDirection::Up;
		else if (yDiff > 0)
			direction_ = MoveDirection::Down;

		position_ = newPosition;
	}

	void Player::PickItems(std::list<GameObject*>& objects)
	{
		for (std::list<GameObject*>::iterator it = objects.begin(); it != objects.end(); ++it)
		{
			Item* item = dynamic_cast<Item*>(*it);
			if ((item != nullptr) && item->IsAlive() && item->IsCollidingWith(*this))
			{
				switch (item->GetType())
				{
					case ItemType::Bomb:
						maxBombs_++;
						availableBombs_++;
						break;
					case ItemType::Power:
						power_++;
						break;
					case ItemType::Speed:
						speedModifier_ += 0.2f;
						break;
					default:
						throw AppException("Unexpected enum value.", "Player::PickItems");
				}
				item->Kill();
			}
		}
	}

	void Player::Kill(void)
	{
		life_--;
	}

	bool Player::CanExplode(bool& block) const
	{
		block = false;
		return true;
	}
}