#ifndef GRAPHDICT_H
#define GRAPHDICT_H


typedef char String[20];
#define EMPTY "Empty"
#define DELETED "Deleted"

typedef struct {
    String *data;
    int count;
    int max;
} Value;

typedef struct {
    String key;
    Value list;
} Node;

typedef struct {
    Node dict[26];
} Dictionary;


void initDict(Dictionary* d, int size);
int hash(String word);
bool addVertex(Dictionary *d, String word);
bool addEdge(Dictionary* dictionary, String src, String edge);
void display(Dictionary d);
bool removeVertex(Dictionary* d, String word);
bool removeEdge(Dictionary* dictionary, String src, String edge);
void BFS(Dictionary d, String start);



#endif
