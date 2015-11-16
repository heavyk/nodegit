#ifndef GITGRAPH_H
#define GITGRAPH_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/oid.h"

using namespace node;
using namespace v8;

class GitGraph : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

             

  private:


             
    static NAN_METHOD(JSNewFunction);


    struct AheadBehindBaton {
      int error_code;
      const git_error* error;
      size_t * ahead;
      size_t * behind;
      git_repository * repo;
      const git_oid * local;
      bool localNeedsFree;
      const git_oid * upstream;
      bool upstreamNeedsFree;
    };
    class AheadBehindWorker : public Nan::AsyncWorker {
      public:
        AheadBehindWorker(
            AheadBehindBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~AheadBehindWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        AheadBehindBaton *baton;
    };

    static NAN_METHOD(AheadBehind);

    static NAN_METHOD(DescendantOf);
};

#endif
