/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EGG_NUMBER = 258,
     EGG_ULONG = 259,
     EGG_STRING = 260,
     ANIMPRELOAD = 261,
     BEZIERCURVE = 262,
     BFACE = 263,
     BILLBOARD = 264,
     BILLBOARDCENTER = 265,
     BINORMAL = 266,
     BUNDLE = 267,
     CLOSED = 268,
     COLLIDE = 269,
     COMMENT = 270,
     COMPONENT = 271,
     COORDSYSTEM = 272,
     CV = 273,
     DART = 274,
     DNORMAL = 275,
     DRGBA = 276,
     DUV = 277,
     DXYZ = 278,
     DCS = 279,
     DISTANCE = 280,
     DTREF = 281,
     DYNAMICVERTEXPOOL = 282,
     EXTERNAL_FILE = 283,
     GROUP = 284,
     DEFAULTPOSE = 285,
     JOINT = 286,
     KNOTS = 287,
     INCLUDE = 288,
     INSTANCE = 289,
     LINE = 290,
     LOOP = 291,
     MATERIAL = 292,
     MATRIX3 = 293,
     MATRIX4 = 294,
     MODEL = 295,
     MREF = 296,
     NORMAL = 297,
     NURBSCURVE = 298,
     NURBSSURFACE = 299,
     OBJECTTYPE = 300,
     ORDER = 301,
     OUTTANGENT = 302,
     POINTLIGHT = 303,
     POLYGON = 304,
     REF = 305,
     RGBA = 306,
     ROTATE = 307,
     ROTX = 308,
     ROTY = 309,
     ROTZ = 310,
     SANIM = 311,
     SCALAR = 312,
     SCALE = 313,
     SEQUENCE = 314,
     SHADING = 315,
     SWITCH = 316,
     SWITCHCONDITION = 317,
     TABLE = 318,
     TABLE_V = 319,
     TAG = 320,
     TANGENT = 321,
     TEXLIST = 322,
     TEXTURE = 323,
     TLENGTHS = 324,
     TRANSFORM = 325,
     TRANSLATE = 326,
     TREF = 327,
     TRIANGLEFAN = 328,
     TRIANGLESTRIP = 329,
     TRIM = 330,
     TXT = 331,
     UKNOTS = 332,
     UV = 333,
     AUX = 334,
     VKNOTS = 335,
     VERTEX = 336,
     VERTEXANIM = 337,
     VERTEXPOOL = 338,
     VERTEXREF = 339,
     XFMANIM = 340,
     XFMSANIM = 341,
     START_EGG = 342,
     START_GROUP_BODY = 343,
     START_TEXTURE_BODY = 344,
     START_PRIMITIVE_BODY = 345
   };
#endif
/* Tokens.  */
#define EGG_NUMBER 258
#define EGG_ULONG 259
#define EGG_STRING 260
#define ANIMPRELOAD 261
#define BEZIERCURVE 262
#define BFACE 263
#define BILLBOARD 264
#define BILLBOARDCENTER 265
#define BINORMAL 266
#define BUNDLE 267
#define CLOSED 268
#define COLLIDE 269
#define COMMENT 270
#define COMPONENT 271
#define COORDSYSTEM 272
#define CV 273
#define DART 274
#define DNORMAL 275
#define DRGBA 276
#define DUV 277
#define DXYZ 278
#define DCS 279
#define DISTANCE 280
#define DTREF 281
#define DYNAMICVERTEXPOOL 282
#define EXTERNAL_FILE 283
#define GROUP 284
#define DEFAULTPOSE 285
#define JOINT 286
#define KNOTS 287
#define INCLUDE 288
#define INSTANCE 289
#define LINE 290
#define LOOP 291
#define MATERIAL 292
#define MATRIX3 293
#define MATRIX4 294
#define MODEL 295
#define MREF 296
#define NORMAL 297
#define NURBSCURVE 298
#define NURBSSURFACE 299
#define OBJECTTYPE 300
#define ORDER 301
#define OUTTANGENT 302
#define POINTLIGHT 303
#define POLYGON 304
#define REF 305
#define RGBA 306
#define ROTATE 307
#define ROTX 308
#define ROTY 309
#define ROTZ 310
#define SANIM 311
#define SCALAR 312
#define SCALE 313
#define SEQUENCE 314
#define SHADING 315
#define SWITCH 316
#define SWITCHCONDITION 317
#define TABLE 318
#define TABLE_V 319
#define TAG 320
#define TANGENT 321
#define TEXLIST 322
#define TEXTURE 323
#define TLENGTHS 324
#define TRANSFORM 325
#define TRANSLATE 326
#define TREF 327
#define TRIANGLEFAN 328
#define TRIANGLESTRIP 329
#define TRIM 330
#define TXT 331
#define UKNOTS 332
#define UV 333
#define AUX 334
#define VKNOTS 335
#define VERTEX 336
#define VERTEXANIM 337
#define VERTEXPOOL 338
#define VERTEXREF 339
#define XFMANIM 340
#define XFMSANIM 341
#define START_EGG 342
#define START_GROUP_BODY 343
#define START_TEXTURE_BODY 344
#define START_PRIMITIVE_BODY 345




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE eggyylval;

