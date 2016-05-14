//
// $Id$

#include <main.h>
#include <AppConfig.h>
#include <AppConfigGgoBackEnd.h>
#include <cmdline.h>

gengetopt_args_info arg_info;
F::AppConfig inidat;

int main (int argc, char* argv[])
{
    COPYRIGHT("test AppConfig", "0.1");


    //F::AppConfigIniBackEnd VLF_Cnvt("VLF_Cnvt.ini");
    //inidat.AddNewConfigSource( &VLF_Cnvt );
    
    F::AppConfigGgoBackEnd cla(argc, argv, &arg_info);
    inidat.AddNewConfigSource( &cla );

    inidat.ParseConfiguration();
    inidat.info();
    
    cout<<"Files/files = "<<inidat.Value("Files", "files", "raté")<<endl;
    cout<<"Etalonnage/Interfranges = "<<inidat.Value("Etalonnage", "Interfranges", "raté")<<endl;
    cout<<"Nb files : "<<inidat.NbKeyInGroup("unnamedoptions")<<endl;
    cout<<"Nb clef in [Fichiers] : "<<inidat.NbKeyInGroup("Fichiers")<<endl;
    return 0;
}


//./tst -f totofile.dat --outDir=~/Data/ -e essai.ini -q file1.dat file2.dat
