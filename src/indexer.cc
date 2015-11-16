// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/indexer.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/transfer_progress.h"
  #include "../include/oid.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitIndexer::GitIndexer(git_indexer *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitIndexer::~GitIndexer() {
      if (this->selfFreeing) {
        git_indexer_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
             }

  void GitIndexer::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Indexer").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "commit", Commit);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "hash", Hash);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Indexer").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitIndexer::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitIndexer cannot be instantiated.");
     }

    GitIndexer* object = new GitIndexer(static_cast<git_indexer *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitIndexer::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitIndexer::constructor_template), 2, argv).ToLocalChecked());
  }

  git_indexer *GitIndexer::GetValue() {
    return this->raw;
  }

  git_indexer **GitIndexer::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitIndexer::ClearValue() {
    this->raw = NULL;
  }

  
/*
   * @param TransferProgress stats
     * @return Number  result    */
NAN_METHOD(GitIndexer::Commit) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TransferProgress stats is required.");
  }

// start convert_from_v8 block
  git_transfer_progress * from_stats;
  from_stats = Nan::ObjectWrap::Unwrap<GitTransferProgress>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_indexer_commit(
Nan::ObjectWrap::Unwrap<GitIndexer>(info.This())->GetValue()
,from_stats
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitIndexer::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitIndexer>(info.This())->GetValue() != NULL) {
 git_indexer_free(
Nan::ObjectWrap::Unwrap<GitIndexer>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitIndexer>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitIndexer::Hash) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_indexer_hash(
Nan::ObjectWrap::Unwrap<GitIndexer>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitOid result
       to = GitOid::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitIndexer::constructor_template;
 