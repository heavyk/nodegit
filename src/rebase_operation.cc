// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/rebase_operation.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRebaseOperation::GitRebaseOperation(git_rebase_operation *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitRebaseOperation::~GitRebaseOperation() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitRebaseOperation::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("RebaseOperation").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "type", Type);
         Nan::SetPrototypeMethod(tpl, "id", Id);
         Nan::SetPrototypeMethod(tpl, "exec", Exec);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("RebaseOperation").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitRebaseOperation::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitRebaseOperation cannot be instantiated.");
     }

    GitRebaseOperation* object = new GitRebaseOperation(static_cast<git_rebase_operation *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitRebaseOperation::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitRebaseOperation::constructor_template), 2, argv).ToLocalChecked());
  }

  git_rebase_operation *GitRebaseOperation::GetValue() {
    return this->raw;
  }

  git_rebase_operation **GitRebaseOperation::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitRebaseOperation::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitRebaseOperation::Type) {
      Local<v8::Value> to;

       git_rebase_operation_t
         type =
         Nan::ObjectWrap::Unwrap<GitRebaseOperation>(info.This())->GetValue()->type;
 // start convert_to_v8 block
     to = Nan::New<Number>( type);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitRebaseOperation::Id) {
      Local<v8::Value> to;

       const git_oid
        *
          id =
        &
          Nan::ObjectWrap::Unwrap<GitRebaseOperation>(info.This())->GetValue()->id;
 // start convert_to_v8 block
  
  if (id != NULL) {
    // GitOid id
       to = GitOid::New((void *)id, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitRebaseOperation::Exec) {
      Local<v8::Value> to;

       const char *
         exec =
         Nan::ObjectWrap::Unwrap<GitRebaseOperation>(info.This())->GetValue()->exec;
 // start convert_to_v8 block
  if (exec){
       to = Nan::New<String>(exec).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitRebaseOperation::constructor_template;
 