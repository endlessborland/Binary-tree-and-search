//
//  main.c
//  binarytree
//
//  Created by Денис Скоробогатов on 12.04.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 1000

typedef struct _node {
    struct _node* left;
    struct _node* right;
    int value;
} node_t;

node_t* createnode(int value)
{
    node_t* root = (node_t*) malloc(sizeof(node_t));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void createtree(node_t* root, int value)
{
    if (value > root->value)
    {
        if (root->right != NULL)
            return createtree(root->right, value);
        /* else */
        root->right = createnode(value);
        return;
    }
    /* else */
    if (root->left != NULL)
        return createtree(root->left, value);
    /*else */
    root->left = createnode(value);
    return;
}

node_t* searchmin(node_t* root)
{
    if (root->left != NULL)
        return searchmin(root->left);
    return root;
}

node_t* searchmax(node_t* root)
{
    if (root->right != NULL)
        return searchmax(root->right);
    return root;
}

void sort(node_t* root, int *array)
{
    static int i = 0;
    if (root == NULL)
        return;
    sort(root->left, array);
    array[i] = root->value;
    i++;
    sort(root->right, array);
}

int main(int argc, const char * argv[]) {
    int *array;
    int i;
    int size;
    node_t* root;
    printf("GIMME the array size\n");
    scanf("%d", &size);
    /* initializing an array with random numbers */
    array = (int*) malloc(size * sizeof(int));
    srand((int)time(NULL));
    for (i = 0; i < size; i++)
    {
        array[i] = rand() % MAX_NUMBER;
        printf("%d ", array[i]);
    }
    printf("\n");
    /* creating tree */
    root = createnode(*array);
    for (i = 1; i <size; i++)
        createtree(root, array[i]);
    /* searching for minimum and maximum */
    printf("Minimum is: %d\n", searchmin(root)->value);
    printf("MAximum is: %d\n", searchmax(root)->value);
    /* sorting an array */
    sort(root, array);
    /* printing a sorted array */
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    return 0;
}
