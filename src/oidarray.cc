// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/oidarray.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitOidarray::GitOidarray(git_oidarray *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitOidarray::~GitOidarray() {
      if (this->selfFreeing) {
        git_oidarray_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
      }

  void GitOidarray::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Oidarray").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "free", Free);
           Nan::SetPrototypeMethod(tpl, "ids", Ids);
         Nan::SetPrototypeMethod(tpl, "count", Count);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Oidarray").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitOidarray::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitOidarray cannot be instantiated.");
     }

    GitOidarray* object = new GitOidarray(static_cast<git_oidarray *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitOidarray::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitOidarray::constructor_template), 2, argv).ToLocalChecked());
  }

  git_oidarray *GitOidarray::GetValue() {
    return this->raw;
  }

  git_oidarray **GitOidarray::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitOidarray::ClearValue() {
    this->raw = NULL;
  }

  
/*
     */
NAN_METHOD(GitOidarray::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitOidarray>(info.This())->GetValue() != NULL) {
 git_oidarray_free(
Nan::ObjectWrap::Unwrap<GitOidarray>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitOidarray>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
       NAN_METHOD(GitOidarray::Ids) {
      Local<v8::Value> to;

       git_oid *
          ids =
          Nan::ObjectWrap::Unwrap<GitOidarray>(info.This())->GetValue()->ids;
 // start convert_to_v8 block
  
  if (ids != NULL) {
    // GitOid ids
       to = GitOid::New((void *)ids, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitOidarray::Count) {
      Local<v8::Value> to;

       size_t
         count =
         Nan::ObjectWrap::Unwrap<GitOidarray>(info.This())->GetValue()->count;
 // start convert_to_v8 block
     to = Nan::New<Number>( count);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitOidarray::constructor_template;
 