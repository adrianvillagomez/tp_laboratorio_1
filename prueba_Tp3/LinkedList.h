/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);//LARGO DE LA LISTA
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//RECIBE LA LISTA Y RECIBE EL ELEMENTO QUE DESEA GUARDAR AL FINAL DE LA LISTA//agrega
/// \fn void ll_get*(LinkedList*, int)
/// \brief
/// \param this
/// \param index
void* ll_get(LinkedList* this, int index);//DEVUELVE EL PUNTERO A NUESTRO ELEMENTO(DONDE SE ENCUENTRA NUESTRO ELEMNETO EN NUESTA MEMORIA)RECIBE UN INDICE(LA POSICION)/PARA BUSCAR AL EMPLEADO
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);//PARA BORRAR 1 CON FREE
int ll_clear(LinkedList* this);//limpia la lista 0 null TODO no se usa en el tp
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);//para agregar donde quiera
void* ll_pop(LinkedList* this,int index);// saca de la lista y devuelve lo que habia en ese lugar
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
