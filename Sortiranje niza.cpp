void sort2(int niz[])
{
    int temp, brojac = 0, prolazi = vel - 1;  // razlog sto ide do vel-1 jer ne mozes porediti 5 i 6 clan ako nema 6 clana pa uvijek ides za 1 manje
    bool nijeSortiran;
    do
    {
        nijeSortiran = false;
        for (int i = 0; i < prolazi; i++)
        {
            if (niz[i] > niz[i + 1]) // provjerava da li je prethodnik veci od sljedbenika ako jest zamijenit ce ih
            {
                temp = niz[i];        
                niz[i] = niz[i + 1];
                niz[i + 1] = temp;
                nijeSortiran = true;
            }
            brojac++;

        }
        prolazi--; // smanjuje broj prolaza za jedan jer svaki put se jedan broj sortira
        
    } while (nijeSortiran); // izlazi iz do while kad je nijeSortiran false  
    cout << "Broj prolaza je: " << brojac << endl;
}
