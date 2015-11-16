#ifndef GITFILTER_H
#define GITFILTER_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/sys/filter.h>
}


using namespace node;
using namespace v8;

class GitFilter : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_filter *GetValue();
    git_filter **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitFilter(git_filter *raw, bool selfFreeing);
    ~GitFilter();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Version);
    static NAN_METHOD(Attributes);
    git_filter *raw;
};

#endif
