#ifndef GITINDEXCONFLICTITERATOR_H
#define GITINDEXCONFLICTITERATOR_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_index_conflict_iterator {
};

using namespace node;
using namespace v8;

class GitIndexConflictIterator : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_index_conflict_iterator *GetValue();
    git_index_conflict_iterator **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitIndexConflictIterator(git_index_conflict_iterator *raw, bool selfFreeing);
    ~GitIndexConflictIterator();
 
    static NAN_METHOD(JSNewFunction);

    git_index_conflict_iterator *raw;
};

#endif
