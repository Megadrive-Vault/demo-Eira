#define __NEOGEO__
//#define __GENESIS__
#ifdef __NEOGEO__
	#include <stdlib.h>
	#include <video.h>
#endif
#ifdef __GENESIS__
#include <genesis.h>
#endif
#include "neo_core.h"

/*	VECTOR */
vec2int vec2intMake(int x, int y){
	vec2int rvec2;
	rvec2.x = x;
	rvec2.y = y;
	return rvec2;
}
vec2int vec2intMakeZero(){
	vec2int rvec2;
	rvec2.x = 0;
	rvec2.y = 0;
	return rvec2;
}
Vect2D_s8 Vect2D_s8Make(s8 x, s8 y){
	Vect2D_s8 r;
	r.x = x;
	r.y = y;
	return r;
}
Vect2D_s16 Vect2D_s16Make(s16 x, s16 y){
	Vect2D_s16 r;
	r.x = x;
	r.y = y;
	return r;

}
Vect2D_s32 Vect2D_s32Make(s32 x, s32 y){
	Vect2D_s32 r;
	r.x = x;
	r.y = y;
	return r;
}
Vect2D_u8 Vect2D_u8Make(u8 x, u8 y){
	Vect2D_u8 r;
	r.x = x;
	r.y = y;
	return r;
}
Vect2D_u16 Vect2D_u16Make(u16 x, u16 y){
	Vect2D_u16 r;
	r.x = x;
	r.y = y;
	return r;
}
Vect2D_u32 Vect2D_u32Make(u32 x, u32 y){
	Vect2D_u32 r;
	r.x = x;
	r.y = y;
	return r;
}
Vect2D_s8 Vect2D_s8MakeZero(){
	Vect2D_s8 r;
	r.x = 0;
	r.y = 0;
	return r;
}
Vect2D_s16 Vect2D_s16MakeZero(){
	Vect2D_s16 r;
	r.x = 0;
	r.y = 0;
	return r;
}
Vect2D_s32 Vect2D_s32MakeZero(){
	Vect2D_s32 r;
	r.x = 0;
	r.y = 0;
	return r;
}
Vect2D_u8 Vect2D_u8MakeZero(){
	Vect2D_u8 r;
	r.x = 0;
	r.y = 0;
	return r;
}
Vect2D_u16 Vect2D_u16MakeZero(){
	Vect2D_u16 r;
	r.x = 0;
	r.y = 0;
	return r;
}
Vect2D_u32 Vect2D_u32MakeZero(){
	Vect2D_u32 r;
	r.x = 0;
	r.y = 0;
	return r;
}


/* UTILS */
scrolling scrollingMake(vec2word pos, vec2word posInc, WORD vblFrameSkip){
	scrolling rScrolling;
	rScrolling.pos = pos;
	rScrolling.posInc = posInc;
	rScrolling.vblFrameSkip = vblFrameSkip;
	return rScrolling;

}
scrolling ScrollingMakeZero(){
	scrolling rScrolling;
	rScrolling.pos.x = 0;
	rScrolling.pos.y = 0;
	rScrolling.posInc.x = 0;
	rScrolling.posInc.y = 0;
	rScrolling.vblFrameSkip = 0;
	return rScrolling;
}
void scrollingUpdate(scrolling *scrolling){

}
void pause(WORD vblTempo){
	WORD i = 0;
	for (i = 0; i <= vblTempo; i++){
		wait_vbl();
	}
	_vbl_count -= i;
}

/* UTILS NEOGEO */
vec2int tileSize(vec2int sizePixels){
	return vec2intMake(sizePixels.x / 16, sizePixels.y / 16);
}
WORD tileSizeNB(WORD xPixelsWidth){
	return xPixelsWidth / 16;
}
WORD tileSizeClipping(WORD yPixelsHeigt){
	return yPixelsHeigt / 16;
}
WORD mapTo_xz(WORD yz){
	// permet de convertir yz sur le range xz
	return yz / 17;

}
WORD mapTo_yz(WORD xz){
	return xz * 17;
}
joystick joystickMake(){
	joystick j;
	j.up = j.left = j.right = j.down = j.a = 0;
	return j;
}
void joystickUpdate(joystick *joy){
	WORD joyState;
	joyState = poll_joystick(PORT1, READ_BIOS);
	if (joyState & JOY_UP)		{ joy->up = 1; }
	else { joy->up = 0; }
	if (joyState & JOY_DOWN)	{ joy->down = 1; }
	else { joy->down = 0; }
	if (joyState & JOY_LEFT)	{ joy->left = 1; }
	else { joy->left = 0; }
	if (joyState & JOY_A)		{ joy->a = 1; }
	else { joy->a = 0; }	//LEFT-CTRL
}

/* UTILS GENESIS */
#ifdef __GENESIS__
void sceneInit(s16 spriteCacheSize){
	VDP_clearPlan(APLAN,0);
	VDP_clearPlan(BPLAN,0);
	MEM_init();
	VDP_init();
	VDP_setScreenHeight224();
	VDP_setScreenWidth320();
	if (spriteCacheSize > 0) {
		SPR_clear();
		SPR_init(spriteCacheSize);
	}
}
void scenePlansPositionZero(){
	VDP_setHorizontalScroll(PLAN_A,0);
	VDP_setVerticalScroll(PLAN_A, 0);
	VDP_setHorizontalScroll(PLAN_B,0);
	VDP_setVerticalScroll(PLAN_B, 0);
}
#endif

/*	SPRITE NEOGEO */
#ifdef __NEOGEO__
spr sprMake(WORD idSpr, vec2int pos, vec2int posInc, vec2int size, WORD vblSkipTranslation, vec2int zoom, vec2int zoomInc, WORD vblSkipZoom){
    spr rSprite;   
    rSprite.pos = pos;
    rSprite.posInc = posInc;
    rSprite.zoom = zoom;
    rSprite.zoomInc = zoomInc;    
    rSprite.idSpr = idSpr;
    rSprite.size = size;
    rSprite.nb = size.x/16;
    rSprite.clipping = size.y/16;
    rSprite.vblSkipTranslation = vblSkipTranslation;    
    rSprite.vblSkipZoom = vblSkipZoom;
    rSprite.firstUpdate = 0;
    return rSprite;
}
spr sprMakeZero(){
    spr rSprite;
    rSprite.idSpr = 0;
    rSprite.size = vec2intMakeZero();
    rSprite.nb = 0;
    rSprite.clipping = 0;
    rSprite.pos = vec2intMakeZero();
    rSprite.posInc = vec2intMakeZero();
    rSprite.vblSkipTranslation = 0;
    rSprite.zoom = vec2intMakeZero();
    rSprite.zoomInc = vec2intMakeZero();
    rSprite.vblSkipZoom = 0;
    rSprite.firstUpdate = 0;
    return rSprite;
    
}
spr sprMakeDefault(WORD idSpr){
	spr rSprite;
	rSprite.idSpr = idSpr;
	rSprite.size = vec2intMake(320, 224);
    rSprite.nb = rSprite.size.x/16;
    rSprite.clipping = rSprite.size.y/16;
	rSprite.pos = vec2intMakeZero();
	rSprite.posInc = vec2intMakeZero();
	rSprite.vblSkipTranslation = 0;
	rSprite.zoom = vec2intMake(SIZE_SPR_DEFAULT);
	rSprite.zoomInc = vec2intMakeZero();
	rSprite.vblSkipZoom = 0;
    rSprite.firstUpdate = 0;
	return rSprite;

}
DWORD write_sprite_data_nn(spr sprite,const PTILEMAP tilemap){
	return write_sprite_data(sprite.pos.x, sprite.pos.y, sprite.zoom.x, sprite.zoom.y, sprite.size.y/16, sprite.size.x/16, tilemap);
}
#endif

/*	SPRITE	*/
void sprUpdate(spr *spr){
	if (!spr->firstUpdate){
		//Memorisation des valeurs d origine dans les "slots" orig... de la structure
		spr->firstUpdate = 1;
		spr->origPos.x = spr->pos.x;
		spr->origPos.y = spr->pos.y;
		spr->origPosInc.x = spr->posInc.x;
		spr->origPosInc.y = spr->posInc.y;
		spr->origZoom.x = spr->zoom.x;
		spr->origZoom.y = spr->zoom.y;
		spr->origZoomInc.x = spr->zoomInc.x;
		spr->origZoomInc.y = spr->zoomInc.y;
	}
	if (spr->vblSkipTranslation == 0 || _vbl_count % spr->vblSkipTranslation == 0){
		if (spr->posInc.x != 0) spr->pos.x += spr->posInc.x;
		if (spr->posInc.y != 0) spr->pos.y += spr->posInc.y;
		change_sprite_pos(spr->idSpr, spr->pos.x, spr->pos.y, spr->size.y / 16);
	}
	if (spr->vblSkipZoom == 0 || _vbl_count % spr->vblSkipZoom == 0){
		spr->zoom.x += spr->zoomInc.x;
		spr->zoom.y += spr->zoomInc.y;
		change_sprite_zoom(spr->idSpr, spr->zoom.x, spr->zoom.y, spr->nb);
		//change_sprite_zoomCenter(&spr, spr->zoom.x, spr->zoom.y);
	}
}

/* TRANSFORM NEOGEO */
#ifdef __NEOGEO__
void sprZoomEffectPingPong(spr *spr, WORD minTresh, WORD maxTresh){
	if (_vbl_count % spr->vblSkipZoom == 0){
		if (spr->zoom.x >= maxTresh){
			if (spr->origZoomInc.x > 0){ spr->zoomInc.x = spr->origZoomInc.x * -1; }
			if (spr->origZoomInc.x < 0){ spr->zoomInc.x = spr->origZoomInc.x; }
		}

		if (spr->zoom.x <= minTresh){
			if (spr->origZoomInc.x > 0){ spr->zoomInc.x = spr->origZoomInc.x; }
			if (spr->origZoomInc.x < 0){ spr->zoomInc.x = spr->origZoomInc.x * -1; }
		}
	}
}
#endif

/*	PALETTE NEOGEO */
#ifdef __NEOGEO__
fadeIn fadeInMake(PPALETTE palettes){
	fadeIn r;
	create_fader((const PPALETTE)&palettes[1], &r.fader, 1);
	r.table = &_fade_to_black;
	r.step = 31; //31
	do_fade(1, &r.fader, r.table, 1, r.step);
	return r;
}
void fadeInUpdate(fadeIn *fadeIn, WORD palstart, WORD nb){
	fadeIn->step--; //step--
	do_fade(palstart, &fadeIn->fader, fadeIn->table, nb, fadeIn->step);
}
#endif