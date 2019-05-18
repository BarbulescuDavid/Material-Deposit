#include <iostream>
#include <fstream>
#include <string.h>
#include<limits>
using namespace std;

struct materiale
{
    int id;
    string numeMaterial;
    float pret;
    string kg_buc;
    int cantitate;
} R[50];


int main()
{
    int it=0,x,i;
    bool done = false;
    string argument;
    ifstream file1("depozit.txt");
    while(!file1.eof())
    {
        file1>>R[it].id;
        file1>>R[it].numeMaterial;
        file1>>R[it].pret;
        file1>>R[it].kg_buc;
        file1>>R[it].cantitate;
        it++;
    }

    do
    {
        cout<<"Pentru a afisa lista produselor apasati tasta 1 \n";
        cout<<"Pentru a afisa produsele cu pretul peste 50 lei apasati tasta 2 \n";
        cout<<"Pentru a afisa un anumit produs apasati tasta 3 \n";
        cout<<"Pentru a afisa materialele cu cantitate scazuta (cel mult 4) apasati tasta 4 \n";
        cout<<"Pentru a afisa materialele epuizate apasati tasta 5 \n";
        cout<<"Pentru a iesi apasati tasta 6 \n";
        cin>>x;

        //IN CAZ DE EROARE
        if(cin.fail()) { // NU S-A INTRODUS O CIFRA
        cin.clear(); // SE GOLESC PARAMETRII LOCALI
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // IGNORA BUFFER-UL
    }

        switch(x)
        {
        case 1:
            cout<<"Lista produselor este urmatoare:";
            for(i=0; i<it; i++)
                cout<<R[i].id<<" "<<R[i].numeMaterial<<" "<<R[i].pret<<"lei/"<<R[i].kg_buc<<" "<<R[i].cantitate<<endl;
            break;

        case 2:
            cout<<"Produsele ale caror pret este peste 50 de lei:"<<endl;
            for(i=0; i<it; i++)
            {
                if(R[i].pret >= 50.0)
                    cout<<R[i].id<<" "<<R[i].numeMaterial<<" "<<R[i].pret<<"lei/"<<R[i].kg_buc<<" "<<R[i].cantitate<<endl;
            }
            break;

        case 3:
            cout<<"Introduceti numele produsului dorit cu litere mici: ";
            cin>>argument;
            for(i=0; i<it; i++)
            {
                std::size_t found=R[i].numeMaterial.find(argument);
                if(found!=std::string::npos)
                    cout<<R[i].id<<" "<<R[i].numeMaterial<<" "<<R[i].pret<<"lei/"<<R[i].kg_buc<<" "<<R[i].cantitate<<endl;
            }
            break;

        case 4:
            cout<<"Produsele cu cantitate scazuta(cel mult 4): "<<endl;
            for(i=0; i<it; i++)
            {
                if(R[i].cantitate < 5)
                    cout<<R[i].id<<" "<<R[i].numeMaterial<<" "<<R[i].pret<<"lei/"<<R[i].kg_buc<<" "<<R[i].cantitate<<endl;
            }
            break;

        case 5:
            cout<<"Materiale epuizate: "<<endl;
            for(i=0; i<it; i++)
            {
                if(R[i].cantitate == 0)
                    cout<<R[i].id<<" "<<R[i].numeMaterial<<" "<<R[i].pret<<"lei/"<<R[i].kg_buc<<" "<<R[i].cantitate<<endl;
            }
            break;

        case 6:
            cout<<"La revedere!";
            done=true;
            break;

        }
        cout<<"\n";
    }
    while(!done);
        return 0;
}
