#ifndef GITBRANCHITERATOR_H
#define GITBRANCHITERATOR_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_branch_iterator {
};

using namespace node;
using namespace v8;

class GitBranchIterator : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_branch_iterator *GetValue();
    git_branch_iterator **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitBranchIterator(git_branch_iterator *raw, bool selfFreeing);
    ~GitBranchIterator();
 
    static NAN_METHOD(JSNewFunction);

    git_branch_iterator *raw;
};

#endif
