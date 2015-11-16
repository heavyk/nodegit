#ifndef GITCOMMIT_H
#define GITCOMMIT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/signature.h"
#include "../include/tree.h"
#include "../include/repository.h"
#include "../include/buf.h"
// Forward declaration.
struct git_commit {
};

using namespace node;
using namespace v8;

class GitCommit : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_commit *GetValue();
    git_commit **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                                                                              

  private:


    GitCommit(git_commit *raw, bool selfFreeing);
    ~GitCommit();
                                                                                                              
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Amend);

    static NAN_METHOD(Author);

    static NAN_METHOD(Committer);

    static NAN_METHOD(Create);

    static NAN_METHOD(CreateV);

    static NAN_METHOD(Free);

    struct HeaderFieldBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_commit * commit;
      const char * field;
    };
    class HeaderFieldWorker : public Nan::AsyncWorker {
      public:
        HeaderFieldWorker(
            HeaderFieldBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~HeaderFieldWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        HeaderFieldBaton *baton;
    };

    static NAN_METHOD(HeaderField);

    static NAN_METHOD(Id);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_commit * commit;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
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

    struct LookupPrefixBaton {
      int error_code;
      const git_error* error;
      git_commit * commit;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      size_t len;
    };
    class LookupPrefixWorker : public Nan::AsyncWorker {
      public:
        LookupPrefixWorker(
            LookupPrefixBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupPrefixWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupPrefixBaton *baton;
    };

    static NAN_METHOD(LookupPrefix);

    static NAN_METHOD(Message);

    static NAN_METHOD(MessageEncoding);

    static NAN_METHOD(MessageRaw);

    struct NthGenAncestorBaton {
      int error_code;
      const git_error* error;
      git_commit * ancestor;
      const git_commit * commit;
      unsigned int n;
    };
    class NthGenAncestorWorker : public Nan::AsyncWorker {
      public:
        NthGenAncestorWorker(
            NthGenAncestorBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~NthGenAncestorWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        NthGenAncestorBaton *baton;
    };

    static NAN_METHOD(NthGenAncestor);

    static NAN_METHOD(Owner);

    struct ParentBaton {
      int error_code;
      const git_error* error;
      git_commit * out;
      const git_commit * commit;
      unsigned int n;
    };
    class ParentWorker : public Nan::AsyncWorker {
      public:
        ParentWorker(
            ParentBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ParentWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ParentBaton *baton;
    };

    static NAN_METHOD(Parent);

    static NAN_METHOD(ParentId);

    static NAN_METHOD(Parentcount);

    static NAN_METHOD(RawHeader);

    static NAN_METHOD(Summary);

    static NAN_METHOD(Time);

    static NAN_METHOD(TimeOffset);

    static NAN_METHOD(Tree);

    static NAN_METHOD(TreeId);
    git_commit *raw;
};

#endif
