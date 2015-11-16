#ifndef GITREFS_H
#define GITREFS_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/oid.h"
#include "../include/strarray.h"
#include "../include/object.h"
// Forward declaration.
struct git_reference {
};

using namespace node;
using namespace v8;

class GitRefs : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_reference *GetValue();
    git_reference **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                                                                                                               

  private:


    GitRefs(git_reference *raw, bool selfFreeing);
    ~GitRefs();
                                                                                                                                               
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Cmp);

    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const git_oid * id;
      bool idNeedsFree;
      int force;
      const char * log_message;
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

    struct CreateMatchingBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const git_oid * id;
      bool idNeedsFree;
      int force;
      const git_oid * current_id;
      bool current_idNeedsFree;
      const char * log_message;
    };
    class CreateMatchingWorker : public Nan::AsyncWorker {
      public:
        CreateMatchingWorker(
            CreateMatchingBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateMatchingWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateMatchingBaton *baton;
    };

    static NAN_METHOD(CreateMatching);

    static NAN_METHOD(Delete);

    struct DwimBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * shorthand;
    };
    class DwimWorker : public Nan::AsyncWorker {
      public:
        DwimWorker(
            DwimBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DwimWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DwimBaton *baton;
    };

    static NAN_METHOD(Dwim);

    static NAN_METHOD(EnsureLog);

    static NAN_METHOD(HasLog);

    static NAN_METHOD(IsBranch);

    static NAN_METHOD(IsNote);

    static NAN_METHOD(IsRemote);

    static NAN_METHOD(IsTag);

    static NAN_METHOD(IsValidName);

    struct ListBaton {
      int error_code;
      const git_error* error;
      git_strarray * array;
      git_repository * repo;
    };
    class ListWorker : public Nan::AsyncWorker {
      public:
        ListWorker(
            ListBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ListWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ListBaton *baton;
    };

    static NAN_METHOD(List);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
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

    static NAN_METHOD(Name);

    struct NameToIdBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const char * name;
    };
    class NameToIdWorker : public Nan::AsyncWorker {
      public:
        NameToIdWorker(
            NameToIdBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~NameToIdWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        NameToIdBaton *baton;
    };

    static NAN_METHOD(NameToId);

    static NAN_METHOD(NormalizeName);

    static NAN_METHOD(Owner);

    struct PeelBaton {
      int error_code;
      const git_error* error;
      git_object * out;
      git_reference * ref;
      git_otype type;
    };
    class PeelWorker : public Nan::AsyncWorker {
      public:
        PeelWorker(
            PeelBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~PeelWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        PeelBaton *baton;
    };

    static NAN_METHOD(Peel);

    static NAN_METHOD(Remove);

    struct RenameBaton {
      int error_code;
      const git_error* error;
      git_reference * new_ref;
      git_reference * ref;
      const char * new_name;
      int force;
      const char * log_message;
    };
    class RenameWorker : public Nan::AsyncWorker {
      public:
        RenameWorker(
            RenameBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~RenameWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        RenameBaton *baton;
    };

    static NAN_METHOD(Rename);

    struct ResolveBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      const git_reference * ref;
    };
    class ResolveWorker : public Nan::AsyncWorker {
      public:
        ResolveWorker(
            ResolveBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ResolveWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ResolveBaton *baton;
    };

    static NAN_METHOD(Resolve);

    struct SetTargetBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_reference * ref;
      const git_oid * id;
      bool idNeedsFree;
      const char * log_message;
    };
    class SetTargetWorker : public Nan::AsyncWorker {
      public:
        SetTargetWorker(
            SetTargetBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SetTargetWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SetTargetBaton *baton;
    };

    static NAN_METHOD(SetTarget);

    static NAN_METHOD(Shorthand);

    struct SymbolicCreateBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const char * target;
      int force;
      const char * log_message;
    };
    class SymbolicCreateWorker : public Nan::AsyncWorker {
      public:
        SymbolicCreateWorker(
            SymbolicCreateBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SymbolicCreateWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SymbolicCreateBaton *baton;
    };

    static NAN_METHOD(SymbolicCreate);

    struct SymbolicCreateMatchingBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * name;
      const char * target;
      int force;
      const char * current_value;
      const char * log_message;
    };
    class SymbolicCreateMatchingWorker : public Nan::AsyncWorker {
      public:
        SymbolicCreateMatchingWorker(
            SymbolicCreateMatchingBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SymbolicCreateMatchingWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SymbolicCreateMatchingBaton *baton;
    };

    static NAN_METHOD(SymbolicCreateMatching);

    struct SymbolicSetTargetBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_reference * ref;
      const char * target;
      const char * log_message;
    };
    class SymbolicSetTargetWorker : public Nan::AsyncWorker {
      public:
        SymbolicSetTargetWorker(
            SymbolicSetTargetBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SymbolicSetTargetWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SymbolicSetTargetBaton *baton;
    };

    static NAN_METHOD(SymbolicSetTarget);

    static NAN_METHOD(SymbolicTarget);

    static NAN_METHOD(Target);

    static NAN_METHOD(TargetPeel);

    static NAN_METHOD(Type);
    git_reference *raw;
};

#endif
