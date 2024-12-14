#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

class ArbolLex {
public:
    static const int N = 4;
    void xNiveles() ;
private:
    int Arbol [N] = {1,2,3,0};
};

void ArbolLex::xNiveles()
{

    for (int i = 0; i < N; i++)
    {
        if (Arbol[i] == 0) Arbol[i] = -1;
        std:: cout <<"indice: " + i << " llave: "+Arbol[i] << " indice padre: "+(i -1)/2<<std::endl;
    }
}
int main()
{

    auto arbolLex = ArbolLex();
    arbolLex.xNiveles();
    return 0;
}

  // TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.