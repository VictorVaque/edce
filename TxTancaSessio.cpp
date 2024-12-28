#include "TxTancaSessio.h"

TxTancaSessio::TxTancaSessio() {}

void TxTancaSessio::executar() {   
    PetitFlix& p = PetitFlix::getInstance();
	p.tanca_sessio();
}
