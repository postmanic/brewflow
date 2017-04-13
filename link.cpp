// 
// 
// 

#include "link.h"

void link_init()
{


}

void link_receive(String inputString, _brewReceipe &b, _iLock &l, int arr[])
{
		Serial.println(inputString);

		switch (arr[0]) {

		case 9010:  //fyld opskrift
			b.mashintarget	= arr[1];
			b.step1target	= arr[2];
			b.step2target	= arr[3];
			b.step3target	= arr[4];
			b.step4target	= arr[5];
			b.mashouttarget	= arr[6];
			b.boiltarget	= arr[7];
			b.mashintime	= arr[8];
			b.step1time		= arr[9];
			b.step2time		= arr[10];
			b.step3time		= arr[11];
			b.step4time		= arr[12];
			b.mashouttime	= arr[13];
			b.boiltime		= arr[14];
			break;

		case 2010:  // Indstilling af debug temp. Simulerer temp probe1
			//debugtemp1 = bbuf_int; // ikke ind i temperatur settings men en del af debug
			//debugtemp1 = debugtemp1 / 10;
			break;
		case 2020:  // Indstilling af debug temp. Simulerer temp probe1
			//debugtemp2 = bbuf_int;
			//debugtemp2 = debugtemp2 / 10;
			break;
		case 9041:  // Bruger bekræfter at der er påfyldt vand. ilock kan kun sættes fra initialisering.
			if (!l.water) {
				l.water = true;
			}
			break;
		case 9042:  // User acknowledges that there is water in tank. No water will damage equipment
			//if (bbuf_int == 2 && l.water) {
				l.grain = true;
			//}
			break;
		case 9050:  // User acknowledges that there is water in tank. No water will damage equipment
			if (l.water && l.grain) {
				l.mashout = true;
			}
			break;
		case 9090: // Hvis der tilsat vand og Mash In temp er indtastet bliver menu sat til 1 
			//myiLock. wspeed1 = bbuf_int;
			//update_pump();
			break;

		case 9092: // Hvis der tilsat vand og Mash In temp er indtastet bliver menu sat til 1 
			//wspeed1 = bbuf_int;
			//myiLock.pumpstate = 0;
			//update_pump();
			break;

		case 9095: // Hvis der tilsat vand og Mash In temp er indtastet bliver menu sat til 1 
			//wspeed1 = bbuf_int;
			//myiLock.pumpstate = 1;
			//update_pump();
			break;

		default:
			// statements, allways statements
			break;
			

	}
}

void link_transmit(int Command, int nop[])
{
	Serial.print(Command);
	for (int x = 1; x<nop[0]; x++) {
		Serial.print(",");
		Serial.print(nop[x]);
	}
	Serial.println();
}

void link_send_temp(float arr[], int updateperiod)
{
	static int lastupdate;
	if (millis() / 1000 >= (lastupdate + updateperiod)) {
		lastupdate = millis() / 1000;
		int nop[] = { 5, arr[0], arr[1], arr[1], lastupdate };
		link_transmit(1012, nop);
	}
}

void link_send_settings(_pid_params &pidp, _iLock &ilock, int *yk, int updateperiod)
{
	static int lastupdate;
	if (millis() / 1000 >= (lastupdate + updateperiod)) {
		lastupdate = millis() / 1000;
		int nop[] = { 10, pidp.steptarget, pidp.steptimer, ilock.water, ilock.grain, ilock.mashout, ilock.vrg, ilock.pumpstate, *yk, lastupdate };
		link_transmit(1010, nop);
	}
}

void link_send_receipe(_brewReceipe &b, int updateperiod)
{
	static int lastupdate;
	if (millis() / 1000 >= (lastupdate + updateperiod)) {
		lastupdate = millis() / 1000;
		int nop[] = { 16, b.mashintarget, b.step1target, b.step2target, b.step3target, b.step4target, b.mashouttarget, b.boiltarget, b.mashintime, b.step1time, b.step2time, b.step3time, b.step4time, b.mashouttime, b.boiltime, lastupdate };
		link_transmit(1022, nop);
	}

}

