
/*
The purpose of this program is to call a Dll created by LabVIEW in C.  This is designed
to show you that LabVIEW can be useful even if you are forced to use it from another
development enviornment.  This program calls three functions from the LV_AAP.dll.
These functions are Aqcuire, Analyze, and Present.  These functions emphasize three
of LabVIEW's signature strengths, which include acquiring data, analyzing data, and
presenting the data on a state of the art GUI.   
*/

/*
The following three headers do not need to be included for this application, but may be 
necessary when calling some LabVIEW dll's depending upon the data types passed and the 
features used.  They can be found at the following directory:
C:\Program Files\National Instruments\LabVIEW 7.0\cintools

#include "platdefines.h"  
#include "fundtypes.h"  
#include "extcode.h"  //extcode.h is included in LV_AAP.h	  
*/

#include <stdio.h>   
#include "LV_AAP.h"

/*
The main VI walks the user through calling three LabVIEW functions from a LabVIEW dll.
Each function was created as a seperate LabVIEW VI and then the VI's were built together
as a DLL.  To rebuild the dll, simply choose "Tools->Build Shared Library" from 
LabVIEW and then load the attached build script (.bld file).  
*/

int main ()
{
	double sineWave[1000], magnitude[20];
	printf("press any key to...\n\n");
	printf("1: Acquire");
	getchar();
	fflush(stdin);
	Acquire(sineWave, 1000);
	/*
	The Acquire function uses the built in Sine Waveform.vi in LabVIEW to generate a 
	sine wave.  It then passes in a reference to the sineWave array along with its size
	and stores the Y values of the sine wave to the sineWave array.  The sine wave is 
	generated for the sake of the example.  In a more practical application, one might 
	use LabVIEW to read data from a DAQ device.
	*/
	printf("Sine wave data aquired by LabVIEW!\n\n");
	printf("2: Analyze");
	getchar();
	fflush(stdin);
	Analyze(sineWave, magnitude, 1000, 20);  
	/*
	The Analyze function uses the built in FFT Power Spectrum.vi in LabVIEW to compute 
	the power spectrum FFT of the sine wave generated in "Aquire." It passes in a 
	reference to the sineWave array and the magnitude array  (along with their sizes) 
	and it stores the analyzed data in the magnitude array.
	*/
	printf("FFT analysis performed on sine wave data by LabVIEW!\n\n");
	printf("3: Present");
	getchar();
	Present(magnitude, sineWave, 20, 1000);
	printf("Data displayed beautifully by LabVIEW!\n");
	
	/*
	The Present function passes in a reference to both data arrays (and their sizes) 
	and displays this data on the LAbVIEW waveform graph.
	*/
	return 0;
}
