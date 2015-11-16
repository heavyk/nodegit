#ifndef GITREFSPEC_H
#define GITREFSPEC_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitRefspec : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_refspec *GetValue();
    git_refspec **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                     

  private:


    GitRefspec(git_refspec *raw, bool selfFreeing);
    ~GitRefspec();
                     
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Direction);

    static NAN_METHOD(Dst);

    static NAN_METHOD(DstMatches);

    static NAN_METHOD(Force);

    static NAN_METHOD(Src);

    static NAN_METHOD(SrcMatches);
    git_refspec *raw;
};

#endif
