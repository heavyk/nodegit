#ifndef GITRESET_H
#define GITRESET_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/object.h"
#include "../include/checkout_options.h"
#include "../include/strarray.h"
#include "../include/annotated_commit.h"

using namespace node;
using namespace v8;

class GitReset : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

                  

  private:


                  
    static NAN_METHOD(JSNewFunction);


    struct ResetBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_object * target;
      git_reset_t reset_type;
      git_checkout_options * checkout_opts;
    };
    class ResetWorker : public Nan::AsyncWorker {
      public:
        ResetWorker(
            ResetBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ResetWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ResetBaton *baton;
    };

    static NAN_METHOD(Reset);

    struct DefaultBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_object * target;
      git_strarray * pathspecs;
    };
    class DefaultWorker : public Nan::AsyncWorker {
      public:
        DefaultWorker(
            DefaultBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DefaultWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DefaultBaton *baton;
    };

    static NAN_METHOD(Default);

    static NAN_METHOD(FromAnnotated);
};

#endif
