#include "BST.h"
#include "RBTree.h"
#include "SplayTree.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include <chrono> 

using namespace std::chrono;
using namespace std;



int main() {
    fstream data_1_file;
    fstream data_2_file;
    fstream search_data_file;
    fstream delete_data_file;
    
    int data_1[10000];
    int data_2[10000];
    int search_data[1000];
    int delete_data[1000];
    int i;

    //data1
    data_1_file.open("data/data_1.txt",ios::in);
       if (data_1_file.is_open()){
        string var;
        i = 0;
        while(getline(data_1_file, var)){
            stringstream geek(var);
            geek >> data_1[i++];
        }
        data_1_file.close();
       }
       
    
    //data2
    data_2_file.open("data/data_2.txt",ios::in);
       if (data_2_file.is_open()){
        string var;
        i = 0;
        while(getline(data_2_file, var)){
            stringstream geek(var);
            geek >> data_2[i++];
        }
        data_2_file.close();
       }

    // search
    search_data_file.open("data/search_data.txt",ios::in);
       if (search_data_file.is_open()){
        string var;
        i = 0;
        while(getline(search_data_file, var)){
            stringstream geek(var);
            geek >> search_data[i++];
        }
        search_data_file.close();
       }
    
    // delete
    delete_data_file.open("data/delete_data.txt",ios::in);
       if (delete_data_file.is_open()){
        string var;
        i = 0;
        while(getline(delete_data_file, var)){
            stringstream geek(var);
            geek >>delete_data[i++];
        }
        delete_data_file.close();
       }
    

    RBTree		*RB_tree_data1;
    BST 		*BS_tree_data1;
    SplayTree 	*splay_tree_data1;

    RBTree		*RB_tree_data2;
    BST 		*BS_tree_data2;
    SplayTree 	*splay_tree_data2;

    RB_tree_data1 =	new RBTree();
    BS_tree_data1 = new BST();
    splay_tree_data1 = new SplayTree();
    
    RB_tree_data2 =	new RBTree();
    BS_tree_data2 = new BST();
    splay_tree_data2 = new SplayTree();

    //data_1 Insertion

    //Red Black tree
    auto start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 10000; i++)
    {
        RB_tree_data1 -> put(data_1[i], 0);
    }
    auto stop_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop_time - start_time);
    int insertion_time_RBT_data1 = duration.count();
    int height_RBT_data1 = RB_tree_data1 -> height();
    
    //Binary Search Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 10000; i++)
    {
        BS_tree_data1 ->put(data_1[i], 0);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int insertion_time_BST_data1 = duration.count();
    int height_BST_data1 = BS_tree_data1 -> height();

    //Splay Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 10000; i++)
    {
        splay_tree_data1 -> put(data_1[i], 0);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int insertion_time_ST_data1 = duration.count();
    int height_ST_data1 = splay_tree_data1 -> height();


    //data_2 Insertion   

    //Red Black Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 10000; i++)
    {
        RB_tree_data2 -> put(data_2[i], 0);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int insertion_time_RBT_data2 = duration.count();
    int height_RBT_data2 = RB_tree_data2 -> height();

    //Binary Search Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 10000; i++)
    {
        BS_tree_data2 ->put(data_2[i], 0);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int insertion_time_BST_data2 = duration.count();
    int height_BST_data2 = BS_tree_data2 -> height();
    

    //Splay Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 10000; i++)
    {
        splay_tree_data2 -> put(data_2[i], 0);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int insertion_time_ST_data2 = duration.count();
    int height_ST_data2 = splay_tree_data2 -> height();


    printf("\ndata_1 Insertion Results\n");
    printf("Insertion Time - RB_Tree: %d\n", insertion_time_RBT_data1);
    printf("Insertion Time - Basic BST: %d\n", insertion_time_BST_data1);
    printf("Insertion Time - Splay Tree: %d\n", insertion_time_ST_data1);
    printf("Tree Height- RB_Tree: %d\n", height_RBT_data1);
    printf("Tree Height- Basic BST: %d\n", height_BST_data1);
    printf("Tree Height- Splay Tree: %d\n", height_ST_data1);

    printf("\ndata_2 Insertion Results\n");
    printf("Insertion Time - RB_Tree: %d\n", insertion_time_RBT_data2);
    printf("Insertion Time - Basic BST: %d\n", insertion_time_BST_data2);
    printf("Insertion Time - Splay Tree: %d\n", insertion_time_ST_data2);
    printf("Tree Height- RB_Tree: %d\n", height_RBT_data2);
    printf("Tree Height- Basic BST: %d\n", height_BST_data2);
    printf("Tree Height- Splay Tree: %d\n", height_ST_data2);
    

    //data_1 Search

    //Red Black Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        RB_tree_data1 ->get(search_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int search_time_RBT_data1 = duration.count();
    height_RBT_data1 = RB_tree_data1 -> height();
    

    //Binary Search Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        BS_tree_data1 ->contains(search_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int search_time_BST_data1 = duration.count();
    height_BST_data1 = BS_tree_data1 -> height();


    //Splay Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        splay_tree_data1 -> contains(search_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int search_time_ST_data1 = duration.count();
    height_ST_data1 = splay_tree_data1 -> height();


    //data_2 Search
    
    //Red black Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        RB_tree_data2 ->get(search_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int search_time_RBT_data2 = duration.count();
    height_RBT_data2 = RB_tree_data2 -> height();


    //Binary Search Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        BS_tree_data2 ->contains(search_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int search_time_BST_data2 = duration.count();
    height_BST_data2 = BS_tree_data2 -> height();


    //Splay Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        splay_tree_data2 -> contains(search_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int search_time_ST_data2= duration.count();
    height_ST_data2 = splay_tree_data2 -> height();

    printf("\ndata_1 Search Results\n");
    printf("Search Time - RB_Tree: %d\n", search_time_RBT_data1);
    printf("Search Time - Basic BST: %d\n", search_time_BST_data1);
    printf("Search Time - Splay Tree: %d\n", search_time_ST_data1);
    printf("Tree Height- RB_Tree: %d\n", height_RBT_data1);
    printf("Tree Height- Basic BST: %d\n", height_BST_data1);
    printf("Tree Height- Splay Tree: %d\n", height_ST_data1);

    printf("\ndata_2 Search Results\n");
    printf("Search Time - RB_Tree: %d\n", search_time_RBT_data2);
    printf("Search Time - Basic BST: %d\n", search_time_BST_data2);
    printf("Search Time - Splay Tree: %d\n", search_time_ST_data2);
    printf("Tree Height- RB_Tree: %d\n", height_RBT_data2);
    printf("Tree Height- Basic BST: %d\n", height_BST_data2);
    printf("Tree Height- Splay Tree: %d\n", height_ST_data2);

    
// Freeing pointers to re-create and insert data

    free(RB_tree_data1);
    free(BS_tree_data1);
    free(splay_tree_data1);

    free(RB_tree_data2);
    free(BS_tree_data2);
    free(splay_tree_data2);

    RB_tree_data1 =	new RBTree();
    BS_tree_data1 = new BST();
    splay_tree_data1 = new SplayTree();
    
    RB_tree_data2 =	new RBTree();
    BS_tree_data2 = new BST();
    splay_tree_data2 = new SplayTree();

    //data1 insertion
    //Red Black Tree
    for (size_t i = 0; i < 10000; i++)
    {
        RB_tree_data1 -> put(data_1[i], 0);
    }

    //Binary Search Tree
    for (size_t i = 0; i < 10000; i++)
    {
        BS_tree_data1 ->put(data_1[i], 0);
    }

    //Splay Tree
    for (size_t i = 0; i < 10000; i++)
    {
        splay_tree_data1 -> put(data_1[i], 0);
    }


    //data2 insertion  
    //Red Black Tree
    for (size_t i = 0; i < 10000; i++)
    {
        RB_tree_data2 -> put(data_2[i], 0);
    }

    //Binary Search Tree
    for (size_t i = 0; i < 10000; i++)
    {
        BS_tree_data2 ->put(data_2[i], 0);
    }
    
    //Splay Tree
    for (size_t i = 0; i < 10000; i++)
    {
        splay_tree_data2 -> put(data_2[i], 0);
    }


    //data_1 Deletion
    //Red Black Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        RB_tree_data1 -> del(delete_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int deletion_time_RBT_data1 = duration.count();
    height_RBT_data1 = RB_tree_data1 -> height();


    //Binary Search Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        BS_tree_data1 -> del(delete_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int deletion_time_BST_data1 = duration.count();
    height_BST_data1 = BS_tree_data1 -> height();
    

    //Splay Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        splay_tree_data1 -> del(delete_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int deletion_time_ST_data1 = duration.count();
    height_ST_data1 = splay_tree_data1 -> height();


    //data_2 Deletion
    //Red Black Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        RB_tree_data2 -> del(delete_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int deletion_time_RBT_data2 = duration.count();
    height_RBT_data2 = RB_tree_data2 -> height();


    //Binary Search Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        BS_tree_data2 -> del(delete_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int deletion_time_BST_data2= duration.count();
    height_BST_data2 = BS_tree_data2 -> height();


    //Splay Tree
    start_time = high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        splay_tree_data2 -> del(delete_data[i]);
    }
    stop_time = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop_time - start_time);
    int deletion_time_ST_data2 = duration.count();
    height_ST_data2 = splay_tree_data2 -> height();

    printf("\ndata_1 Deletion Results\n");
    printf("Deletion Time - RB_Tree: %d\n", deletion_time_RBT_data1);
    printf("Deletion Time - Basic BST: %d\n", deletion_time_BST_data1);
    printf("Deletion Time - Splay Tree: %d\n", deletion_time_ST_data1);
    printf("Tree Height- RB_Tree: %d\n", height_RBT_data1);
    printf("Tree Height- Basic BST: %d\n", height_BST_data1);
    printf("Tree Height- Splay Tree: %d\n", height_ST_data1);

    printf("\ndata_2 Deletion Results\n");
    printf("Deletion Time - RB_Tree: %d\n", deletion_time_RBT_data2);
    printf("Deletion Time - Basic BST: %d\n", deletion_time_BST_data2);
    printf("Search Time - Splay Tree: %d\n", deletion_time_ST_data2);
    printf("Tree Height- RB_Tree: %d\n", height_RBT_data2);
    printf("Tree Height- Basic BST: %d\n", height_BST_data2);
    printf("Tree Height- Splay Tree: %d\n", height_ST_data2);


    
    return 0;
}