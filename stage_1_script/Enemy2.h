#pragma once
#include "cocos2d.h"
#include "Anime.h"

class Enemy2 {
public:
	float Espeed;//속도
				 //충돌체크
	int number;//객체식별번호 
			   //스프라이트 마다 효과
	void aa();
	cocos2d::Sprite * spriteE;
	int ag; // 각도
	int es;
	Anime*EA;
	void ii();
};