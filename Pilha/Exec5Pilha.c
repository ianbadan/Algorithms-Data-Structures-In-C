/*O fragmento empilha B sempre que a pilha estiver vazia ou se o topo for diferente de A,
porem enquanto a pilha não estiver vazia e o topo for A, ele desempilha ate que a que o while
se torne falso e então empilha B, basicamente, o codigo sempre mantem B como topo, versao
simplificada abaixo*/

if(pilhaVazia() || espiapilha()=!'A') empilha('B');
 else{
    while(!pilhavazia() && espiapilha()== 'A') desempilha();
    empilha('B');
 }
