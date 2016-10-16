#include <iostream>
using namespace std;

#define size[50];
struct tnode{
    int vertex;
    tnode *next;
};

tnode *adj[size]; 
tnode *sngllist=NULL; //Singly Link Listvoid createGraph(){
    tnode *newl,*last;
    int neighbours,neighbour_value;
    cout<<"\n\n---Graph Creation---\n\n";
    cout<<"Enter total nodes in graph : ";
    cin>>totNodes;
    for(int i=1;i<=totNodes;i++){
        last=NULL;
        cout<<"\nEnter no. of nodes in the adjacency list of node "<<i<<"\n";
        cout<<"--> That is Total Neighbours of "<<i<<" : ";
        cin>>n;
        for(int j=1;j<=n;j++){
            cout<<"Enter neighbour #"<<j<<" : ";
            cin>>n_value;
            newl=new node;
            newl->vertex=n_value;
            newl->next=NULL;
            if(adj[i]==NULL)
                adj[i]=last=newl;
            else{
                last->next = newl;
                last = newl;
            }
        }
    }
}


void dfsVisit(int i)
{
    tnode *tmp,*newl;
    int v;

    tmp=adj[i];
    while(tmp != NULL)
    {
        v=tmp->vertex;
        if(status[v]==ready)
            dfsVisit(v);
        tmp=tmp->next;
    }

    newl=new node;
    newl->vertex=i;
    newl->next=sngllist;
    sngllist=newl;
    status[i]=processed;
}



void topologicalSort(){
    int i;

    for(i=1;i<=totNodes;i++)
        status[i]=ready;

    for(i=1;i<=totNodes;i++){
        if(status[i]==ready)
            dfsVisit(i);
    }

    //print listwhile(sngllist!=NULL){
        cout<<"   "<<sngllist->vertex;
        sngllist=sngllist->next;
    }

}


int main()
{
    
    cout<<"*****Topological Sort*****\n";
    createtnode();
    cout<<"\n===Topological Sort is as under===\n";
    topologicalSort();
    return 0;;
}
