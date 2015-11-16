// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/push_update.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitPushUpdate::GitPushUpdate(git_push_update *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitPushUpdate::~GitPushUpdate() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitPushUpdate::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("PushUpdate").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "srcRefname", SrcRefname);
         Nan::SetPrototypeMethod(tpl, "dstRefname", DstRefname);
         Nan::SetPrototypeMethod(tpl, "src", Src);
         Nan::SetPrototypeMethod(tpl, "dst", Dst);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("PushUpdate").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitPushUpdate::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitPushUpdate cannot be instantiated.");
     }

    GitPushUpdate* object = new GitPushUpdate(static_cast<git_push_update *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitPushUpdate::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitPushUpdate::constructor_template), 2, argv).ToLocalChecked());
  }

  git_push_update *GitPushUpdate::GetValue() {
    return this->raw;
  }

  git_push_update **GitPushUpdate::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitPushUpdate::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitPushUpdate::SrcRefname) {
      Local<v8::Value> to;

       char *
         src_refname =
         Nan::ObjectWrap::Unwrap<GitPushUpdate>(info.This())->GetValue()->src_refname;
 // start convert_to_v8 block
  if (src_refname){
       to = Nan::New<String>(src_refname).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitPushUpdate::DstRefname) {
      Local<v8::Value> to;

       char *
         dst_refname =
         Nan::ObjectWrap::Unwrap<GitPushUpdate>(info.This())->GetValue()->dst_refname;
 // start convert_to_v8 block
  if (dst_refname){
       to = Nan::New<String>(dst_refname).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitPushUpdate::Src) {
      Local<v8::Value> to;

       git_oid
        *
          src =
        &
          Nan::ObjectWrap::Unwrap<GitPushUpdate>(info.This())->GetValue()->src;
 // start convert_to_v8 block
  
  if (src != NULL) {
    // GitOid src
       to = GitOid::New((void *)src, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitPushUpdate::Dst) {
      Local<v8::Value> to;

       git_oid
        *
          dst =
        &
          Nan::ObjectWrap::Unwrap<GitPushUpdate>(info.This())->GetValue()->dst;
 // start convert_to_v8 block
  
  if (dst != NULL) {
    // GitOid dst
       to = GitOid::New((void *)dst, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitPushUpdate::constructor_template;
 