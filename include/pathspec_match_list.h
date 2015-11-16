#ifndef GITPATHSPECMATCHLIST_H
#define GITPATHSPECMATCHLIST_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_pathspec_match_list {
};

using namespace node;
using namespace v8;

class GitPathspecMatchList : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_pathspec_match_list *GetValue();
    git_pathspec_match_list **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitPathspecMatchList(git_pathspec_match_list *raw, bool selfFreeing);
    ~GitPathspecMatchList();
 
    static NAN_METHOD(JSNewFunction);

    git_pathspec_match_list *raw;
};

#endif
