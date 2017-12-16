#include "Game_Manager.h"

// 메인 함수
void main(){
	GameManager *GM = new GameManager();

	// 블록 움직임 반복
	for (;1;){
		GM->Keyboard_Check();	// 키보드 체크 후 다시 그려줌
	}
}