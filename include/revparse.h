#ifndef GITREVPARSE_H
#define GITREVPARSE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/object.h"
#include "../include/reference.h"
#include "../include/repository.h"

using namespace node;
using namespace v8;

class GitRevparse : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

            

  private:


            
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Ext);

    struct SingleBaton {
      int error_code;
      const git_error* error;
      git_object * out;
      git_repository * repo;
      const char * spec;
    };
    class SingleWorker : public Nan::AsyncWorker {
      public:
        SingleWorker(
            SingleBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SingleWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SingleBaton *baton;
    };

    static NAN_METHOD(Single);
};

#endif
