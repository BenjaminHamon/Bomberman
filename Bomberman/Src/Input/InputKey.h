#pragma once

namespace Bomberman
{
	struct InputKey
	{
		static const int EnumMax = 350;

		/// <summary>
		/// Enumeration for keyboard keys.
		/// Corresponds to the SDL key enum to use the two as if they are the same.
		/// </summary>
		enum InputKeyEnum
		{
			Unknown = 0,
			Backspace = 8,
			Tab = 9,
			Clear = 12,
			Return = 13,
			Pause = 19,
			Escape = 27,
			Space = 32,
			Exclaim = 33,
			Quotedbl = 34,
			Hash = 35,
			Dollar = 36,
			Ampersand = 38,
			Quote = 39,
			SDLK_LEFTPAREN		= 40,
			SDLK_RIGHTPAREN		= 41,
			SDLK_ASTERISK		= 42,
			SDLK_PLUS		= 43,
			SDLK_COMMA		= 44,
			SDLK_MINUS		= 45,
			SDLK_PERIOD		= 46,
			SDLK_SLASH		= 47,
			SDLK_0			= 48,
			SDLK_1			= 49,
			SDLK_2			= 50,
			SDLK_3			= 51,
			SDLK_4			= 52,
			SDLK_5			= 53,
			SDLK_6			= 54,
			SDLK_7			= 55,
			SDLK_8			= 56,
			SDLK_9			= 57,
			SDLK_COLON		= 58,
			SDLK_SEMICOLON		= 59,
			SDLK_LESS		= 60,
			SDLK_EQUALS		= 61,
			SDLK_GREATER		= 62,
			SDLK_QUESTION		= 63,
			SDLK_AT			= 64,
			/* 
				Skip uppercase letters
				*/
			SDLK_LEFTBRACKET	= 91,
			SDLK_BACKSLASH		= 92,
			SDLK_RIGHTBRACKET	= 93,
			SDLK_CARET		= 94,
			SDLK_UNDERSCORE		= 95,
			SDLK_BACKQUOTE		= 96,
			A = 97,
			B = 98,
			C = 99,
			D = 100,
			E = 101,
			F = 102,
			G = 103,
			H = 104,
			I = 105,
			J = 106,
			K = 107,
			L = 108,
			M = 109,
			N = 110,
			O = 111,
			P = 112,
			Q = 113,
			R = 114,
			S = 115,
			T = 116,
			U = 117,
			V = 118,
			W = 119,
			X = 120,
			Y = 121,
			Z = 122,
			SDLK_DELETE		= 127,
			/* End of ASCII mapped keysyms */
				/*@}*/

			/** @name International keyboard syms */
				/*@{*/
			SDLK_WORLD_0		= 160,		/* 0xA0 */
			SDLK_WORLD_1		= 161,
			SDLK_WORLD_2		= 162,
			SDLK_WORLD_3		= 163,
			SDLK_WORLD_4		= 164,
			SDLK_WORLD_5		= 165,
			SDLK_WORLD_6		= 166,
			SDLK_WORLD_7		= 167,
			SDLK_WORLD_8		= 168,
			SDLK_WORLD_9		= 169,
			SDLK_WORLD_10		= 170,
			SDLK_WORLD_11		= 171,
			SDLK_WORLD_12		= 172,
			SDLK_WORLD_13		= 173,
			SDLK_WORLD_14		= 174,
			SDLK_WORLD_15		= 175,
			SDLK_WORLD_16		= 176,
			SDLK_WORLD_17		= 177,
			SDLK_WORLD_18		= 178,
			SDLK_WORLD_19		= 179,
			SDLK_WORLD_20		= 180,
			SDLK_WORLD_21		= 181,
			SDLK_WORLD_22		= 182,
			SDLK_WORLD_23		= 183,
			SDLK_WORLD_24		= 184,
			SDLK_WORLD_25		= 185,
			SDLK_WORLD_26		= 186,
			SDLK_WORLD_27		= 187,
			SDLK_WORLD_28		= 188,
			SDLK_WORLD_29		= 189,
			SDLK_WORLD_30		= 190,
			SDLK_WORLD_31		= 191,
			SDLK_WORLD_32		= 192,
			SDLK_WORLD_33		= 193,
			SDLK_WORLD_34		= 194,
			SDLK_WORLD_35		= 195,
			SDLK_WORLD_36		= 196,
			SDLK_WORLD_37		= 197,
			SDLK_WORLD_38		= 198,
			SDLK_WORLD_39		= 199,
			SDLK_WORLD_40		= 200,
			SDLK_WORLD_41		= 201,
			SDLK_WORLD_42		= 202,
			SDLK_WORLD_43		= 203,
			SDLK_WORLD_44		= 204,
			SDLK_WORLD_45		= 205,
			SDLK_WORLD_46		= 206,
			SDLK_WORLD_47		= 207,
			SDLK_WORLD_48		= 208,
			SDLK_WORLD_49		= 209,
			SDLK_WORLD_50		= 210,
			SDLK_WORLD_51		= 211,
			SDLK_WORLD_52		= 212,
			SDLK_WORLD_53		= 213,
			SDLK_WORLD_54		= 214,
			SDLK_WORLD_55		= 215,
			SDLK_WORLD_56		= 216,
			SDLK_WORLD_57		= 217,
			SDLK_WORLD_58		= 218,
			SDLK_WORLD_59		= 219,
			SDLK_WORLD_60		= 220,
			SDLK_WORLD_61		= 221,
			SDLK_WORLD_62		= 222,
			SDLK_WORLD_63		= 223,
			SDLK_WORLD_64		= 224,
			SDLK_WORLD_65		= 225,
			SDLK_WORLD_66		= 226,
			SDLK_WORLD_67		= 227,
			SDLK_WORLD_68		= 228,
			SDLK_WORLD_69		= 229,
			SDLK_WORLD_70		= 230,
			SDLK_WORLD_71		= 231,
			SDLK_WORLD_72		= 232,
			SDLK_WORLD_73		= 233,
			SDLK_WORLD_74		= 234,
			SDLK_WORLD_75		= 235,
			SDLK_WORLD_76		= 236,
			SDLK_WORLD_77		= 237,
			SDLK_WORLD_78		= 238,
			SDLK_WORLD_79		= 239,
			SDLK_WORLD_80		= 240,
			SDLK_WORLD_81		= 241,
			SDLK_WORLD_82		= 242,
			SDLK_WORLD_83		= 243,
			SDLK_WORLD_84		= 244,
			SDLK_WORLD_85		= 245,
			SDLK_WORLD_86		= 246,
			SDLK_WORLD_87		= 247,
			SDLK_WORLD_88		= 248,
			SDLK_WORLD_89		= 249,
			SDLK_WORLD_90		= 250,
			SDLK_WORLD_91		= 251,
			SDLK_WORLD_92		= 252,
			SDLK_WORLD_93		= 253,
			SDLK_WORLD_94		= 254,
			SDLK_WORLD_95		= 255,		/* 0xFF */
				/*@}*/

			/** @name Numeric keypad */
				/*@{*/
			SDLK_KP0		= 256,
			SDLK_KP1		= 257,
			SDLK_KP2		= 258,
			SDLK_KP3		= 259,
			SDLK_KP4		= 260,
			SDLK_KP5		= 261,
			SDLK_KP6		= 262,
			SDLK_KP7		= 263,
			SDLK_KP8		= 264,
			SDLK_KP9		= 265,
			SDLK_KP_PERIOD		= 266,
			SDLK_KP_DIVIDE		= 267,
			SDLK_KP_MULTIPLY	= 268,
			SDLK_KP_MINUS		= 269,
			SDLK_KP_PLUS		= 270,
			SDLK_KP_ENTER		= 271,
			SDLK_KP_EQUALS		= 272,
				/*@}*/

			/** @name Arrows + Home/End pad */
				/*@{*/
			UpArrow	= 273,
			DownArrow = 274,
			RightArrow = 275,
			LeftArrow = 276,
			SDLK_INSERT		= 277,
			SDLK_HOME		= 278,
			SDLK_END		= 279,
			SDLK_PAGEUP		= 280,
			SDLK_PAGEDOWN		= 281,
				/*@}*/

			/** @name Function keys */
				/*@{*/
			SDLK_F1			= 282,
			SDLK_F2			= 283,
			SDLK_F3			= 284,
			SDLK_F4			= 285,
			SDLK_F5			= 286,
			SDLK_F6			= 287,
			SDLK_F7			= 288,
			SDLK_F8			= 289,
			SDLK_F9			= 290,
			SDLK_F10		= 291,
			SDLK_F11		= 292,
			SDLK_F12		= 293,
			SDLK_F13		= 294,
			SDLK_F14		= 295,
			SDLK_F15		= 296,
				/*@}*/

			/** @name Key state modifier keys */
				/*@{*/
			SDLK_NUMLOCK		= 300,
			SDLK_CAPSLOCK		= 301,
			SDLK_SCROLLOCK		= 302,
			SDLK_RSHIFT		= 303,
			SDLK_LSHIFT		= 304,
			RightCtrl = 305,
			LeftCtrl = 306,
			SDLK_RALT		= 307,
			SDLK_LALT		= 308,
			SDLK_RMETA		= 309,
			SDLK_LMETA		= 310,
			SDLK_LSUPER		= 311,		/**< Left "Windows" key */
			SDLK_RSUPER		= 312,		/**< Right "Windows" key */
			SDLK_MODE		= 313,		/**< "Alt Gr" key */
			SDLK_COMPOSE		= 314,		/**< Multi-key compose key */
				/*@}*/

			/** @name Miscellaneous function keys */
				/*@{*/
			SDLK_HELP		= 315,
			SDLK_PRINT		= 316,
			SDLK_SYSREQ		= 317,
			SDLK_BREAK		= 318,
			SDLK_MENU		= 319,
			SDLK_POWER		= 320,		/**< Power Macintosh power key */
			SDLK_EURO		= 321,		/**< Some european keyboards */
			SDLK_UNDO		= 322,		/**< Atari keyboard has Undo */
				/*@}*/
		};
	};
}