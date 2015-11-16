#ifndef GITBRANCH_H
#define GITBRANCH_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/reference.h"
#include "../include/repository.h"
#include "../include/commit.h"
#include "../include/annotated_commit.h"
#include "../include/branch_iterator.h"

using namespace node;
using namespace v8;

class GitBranch : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

                                                  

  private:


                                                  
    static NAN_METHOD(JSNewFunction);


    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * branch_name;
      const git_commit * target;
      int force;
    };
    class CreateWorker : public Nan::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateBaton *baton;
    };

    static NAN_METHOD(Create);

    static NAN_METHOD(CreateFromAnnotated);

    static NAN_METHOD(Delete);

    static NAN_METHOD(IsHead);

    struct IteratorNewBaton {
      int error_code;
      const git_error* error;
      git_branch_iterator * out;
      git_repository * repo;
      git_branch_t list_flags;
    };
    class IteratorNewWorker : public Nan::AsyncWorker {
      public:
        IteratorNewWorker(
            IteratorNewBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~IteratorNewWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        IteratorNewBaton *baton;
    };

    static NAN_METHOD(IteratorNew);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * branch_name;
      git_branch_t branch_type;
    };
    class LookupWorker : public Nan::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupBaton *baton;
    };

    static NAN_METHOD(Lookup);

    struct MoveBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_reference * branch;
      const char * new_branch_name;
      int force;
    };
    class MoveWorker : public Nan::AsyncWorker {
      public:
        MoveWorker(
            MoveBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~MoveWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        MoveBaton *baton;
    };

    static NAN_METHOD(Move);

    struct NameBaton {
      int error_code;
      const git_error* error;
      const char * out;
      const git_reference * ref;
    };
    class NameWorker : public Nan::AsyncWorker {
      public:
        NameWorker(
            NameBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~NameWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        NameBaton *baton;
    };

    static NAN_METHOD(Name);

    static NAN_METHOD(SetUpstream);

    static NAN_METHOD(Upstream);
};

#endif
