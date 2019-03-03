#include "../inc/PriorityCar.hpp"

PriorityCar::PriorityCar(bool beacon, int code): Car(){
	this->beacon 	=	beacon;
	this->code		=	code;
}

void PriorityCar::startWithCode(int code){
	if (code != getCode()){
		
	}
}
