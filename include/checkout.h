#ifndef GITCHECKOUT_H
#define GITCHECKOUT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/checkout_options.h"
#include "../include/index.h"
#include "../include/object.h"

using namespace node;
using namespace v8;

class GitCheckout : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

                   

  private:


                   
    static NAN_METHOD(JSNewFunction);


    struct HeadBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_checkout_options * opts;
    };
    class HeadWorker : public Nan::AsyncWorker {
      public:
        HeadWorker(
            HeadBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~HeadWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        HeadBaton *baton;
    };

    static NAN_METHOD(Head);

    struct IndexBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_index * index;
      const git_checkout_options * opts;
    };
    class IndexWorker : public Nan::AsyncWorker {
      public:
        IndexWorker(
            IndexBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~IndexWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        IndexBaton *baton;
    };

    static NAN_METHOD(Index);

    static NAN_METHOD(InitOptions);

    struct TreeBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const git_object * treeish;
      const git_checkout_options * opts;
    };
    class TreeWorker : public Nan::AsyncWorker {
      public:
        TreeWorker(
            TreeBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~TreeWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        TreeBaton *baton;
    };

    static NAN_METHOD(Tree);
};

#endif
