#ifndef GITFILTERLIST_H
#define GITFILTERLIST_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

// Forward declaration.
struct git_filter_list {
};

using namespace node;
using namespace v8;

class GitFilterList : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_filter_list *GetValue();
    git_filter_list **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitFilterList(git_filter_list *raw, bool selfFreeing);
    ~GitFilterList();
 
    static NAN_METHOD(JSNewFunction);

    git_filter_list *raw;
};

#endif
