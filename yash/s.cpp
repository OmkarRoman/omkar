#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 50
#define MAX_USERS 100
// Structure to represent a user (node)
struct user{
    char name[MAX_NAME_LEN];
    struct User* next; 
	// Pointer to next user in the adjancency list 
};
// Structure to represent a graph 
struct Graph{
    int numUsers;
    struct User* adjList[MAX_USERS]; // Arrray of adjecency lists
};
// Function to create a new user node 
struct User* createUser(char* name){
    struct User* newUser = (struct User*)malloc(sizeof(struct User));
    strcpy (newUser->name,name);
    newUser->next = NULL;
    return newUser;
}
// Function to create a graph
struct Graph* createGraph(int numUsers){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numUsers = numUsers;

// Initialize adjacency list
for(int i = 0; i< numUsers;i++){
    graph->adjList[i]=NULL;
}
return graph;
}
// Function to add an edge(friendship) between two users
void addFriendship(struct Graph* graph,int useIndex1,int userIndex2,char* name1,char* name2){
    // Add user2 to user1's adjacency list
    struct User* newUser= createUser(name2);
    newUser->next=graph->adjList[userIndex1];
    graph->adjList[userIndex1]= newUser;
     // Add user1 to user2's adjacency list
    newUser= createUser(name1);
    newUser->next=graph->adjList[userIndex2] = newUser;
}
// Function to print the graph 
void printGraph(struct Graph* graph,char users[][MAX_NAME_LEN]){
    for(int i=0;i<graph->numUsers;i++){
struct User* temp=graph->adjList[i];
printf("\n%s's friends:",user[i]);
while (temp){
    printf("%s",temp->name);
    temp = temp->next;
}
printf("\n");
}
}
int main(){
    int  numUsers = 4;
    struct Graph* graph=createGraph(numUsers);
    // Array to store user names
    char users[4][MAX_NAME_LEN]={"Alice","Bob","Charlie","David"};
    // Add friendships
    addFriendship(graph,0,1,user[0],user[1]); // Alice<-> Bob
    addFriendship(graph,0,2,user[0],user[2]); // Alice<-> Charlie
    addFriendship(graph,1,2,user[1],user[2]); // Bob<-> Charlie
    addFriendship(graph,2,3,user[2],user[3]); // Charlie<-> David
    // Print the graph
    printGraph(graph,users);
    return 0;
}
