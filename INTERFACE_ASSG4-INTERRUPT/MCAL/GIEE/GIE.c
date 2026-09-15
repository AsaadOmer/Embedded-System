/*
 * GIE.c
 *
 * Created: 5/20/2026 10:32:45 PM
 *  Author: Eslam El Hefny
 */ 
void GIE_voidEnableGlobalInterrupt(){
	__asm("sei");
}

void GIE_voidDisableGlobalInterrupt(){
	__asm("cli");
}