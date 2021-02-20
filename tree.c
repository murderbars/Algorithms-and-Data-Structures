tree MakeTree(tree node, int x)
{
    if(node.value == NULL)
    {
        tree* p = new tree;
        p->value = x;
        node = *p;
    }
    else
    {
        if((node).value > x) MakeTree(*node.pleft, x);
        else MakeTree(*node.pright, x);
    }
    return node;
}
void SetLeft (tree *p,int x) // создание левого сына для узла с указателем p
{
    *p->ltree = NewNode(x);
}
void SetRight(tree *p,int x) // создание правого сына для узла с указателем p
{
    *p->rtree = NewNode(x);
}
int GetInfo (tree *p) // чтение значения информационного поля узла p
{
    if (p != NULL) return p->info;
    else return(0);
}
tree GetLeftTree (tree *p) // выдать значение указателя на левое поддерево узла p
{
    if (p != NULL) return *p->ltree;
//else return(NULL);
}
tree GetRightTree (tree *p) //выдать значение указателя на правое поддерево узла p
{
    if (p != NULL) return *p->ltree;
}
void DelLeaf (tree *p) // Удалить в дереве «лист»
{
    if (p != NULL) free(p);
}
void PrefixObhod (tree *p)
{
    if (p !=NULL) // Если дерево не пусто, то префиксный порядок это:
    {
        printf ("%d", p->info); //обработка узла, например напечатем его инф.часть
        PrefixObhod (p->ltree); // Узлы левого поддерева в префиксном порядке
        PrefixObhod (p->rtree); // Узлы правого поддерева в префиксном порядке
    }
}
void InfixObhod (tree *p)
{
    if (p != NULL) // Если дерево не пусто, то инфиксный порядок это:
    {
        InfixObhod (p->ltree); // Узлы левого поддерева в инфиксном порядке
        printf ("%d", p->info); //обработка узла, например напечатем его инф.часть
        InfixObhod (p->rtree); // Узлы правого поддерева в инфиксном порядке
    }
}
void DelSubTree (tree *p) //процедура удаление куста p с использованием суффиксного обхода
{
    if (p != NULL) // Если дерево не пусто, то суффиксный порядок это:
    {
        DelSubTree (p->ltree); // Узлы левого поддерева в суффиксном порядке
        DelSubTree (p->rtree); // Узлы правого поддерева в суффиксном порядке
        free(p); //обработка узла, например удалим узел
    }
}
void DelLeftTree (tree *p) //удаление левого поддерева для узла p
{
    if (p != NULL)
    {
        DelSubTree (p->ltree);
        p->ltree = NULL;
    }
}
void DelRightTree (tree *p) //удаление правого поддерева для узла p
{
    if (p != NULL)
    {
        DelSubTree (p->rtree);
        p->ltree = NULL;
    }
}
bool TreeEqual(tree *p1, tree *p2)
{
    if (p1 == p2) return true;
    else if ((p2 != NULL) && (p1 != NULL))
        return ((p1->info = p2->info) && TreeEqual(p1->ltree, p2->ltree) &&
                TreeEqual(p1->rtree, p2->rtree));
    else return false;
}