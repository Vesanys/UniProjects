/*$T indentinput.cpp GC 1.140 12/06/12 20:39:08 */


/*$6
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */


#include <jni.h>
#include "Rhover.h"
#include "LayerClasses/CVmc.cpp"
#include "LayerClasses/CCommunicationLayer.cpp"
#include "LayerClasses/CTranslationLayer.cpp"
#include "LayerClasses/CvmcAPI.cpp"
#include "Adapter/CComAdapter.cpp"
#include "StorageClasses/CMotor.cpp"
#include "StorageClasses/CStorage.cpp"
#include "SupportClasses/CChannel.cpp"
#include "SupportClasses/CData.cpp"
#include "SupportClasses/CError.cpp"
#include "SupportClasses/CMessage.cpp"
#include "SupportClasses/CMultisend.cpp"
#include "SupportClasses/CRequest.cpp"
#include "SupportClasses/CSendTwo.cpp"
#include "SupportClasses/CTimer.cpp"
#include "SupportClasses/CTimestamp.cpp"

/*
 =======================================================================================================================
 =======================================================================================================================
 */

JNIEXPORT jboolean JNICALL Java_Rhover_isConnected(JNIEnv *env, jclass cls)
{

	/*~~~~~~~~~~*/
	/* chiamata alla libreria sottostante */
	VMC::CVmc	x;			/* istanzio un oggetto CVmc nel namespace VMC */
	/*~~~~~~~~~~*/

	return x.isConnected(); /* chiamo il metodo isConnected() che restituirï¿½ un valore */
	/* il quale indica se ï¿½ presente una connessione con l'RT-6 */
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
JNIEXPORT void JNICALL Java_Rhover_setMotors(JNIEnv *env, jclass cls, jint velocityLeft, jint velocityRight)
{

	/*~~~~~~~~~~*/
	VMC::CVmc	x;	/* istanzio un oggetto CVmc */
	/*~~~~~~~~~~*/

	try
	{
	    /* chiamata alla libreria a basso livello */
		x.setMotors(velocityLeft, velocityRight);
		Sleep(1000);/*indispensabile pèer stabilire x quanti secondi il rhover deve camminare*/
	}
	catch (int e)
	{
		printf("Errore nella chiamata al metodo setMotors\n");
	}
}

/*
 =======================================================================================================================
 =======================================================================================================================
 */
int main()
{ };
