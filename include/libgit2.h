#ifndef GITLIBGIT2_H
#define GITLIBGIT2_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitLibgit2 : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

               

  private:


               
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Features);

    static NAN_METHOD(Init);

    static NAN_METHOD(Opts);

    static NAN_METHOD(Shutdown);

    static NAN_METHOD(Version);
};

#endif
