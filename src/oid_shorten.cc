// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/oid_shorten.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitOidShorten::GitOidShorten(git_oid_shorten *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitOidShorten::~GitOidShorten() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitOidShorten::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("OidShorten").ToLocalChecked());

  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("OidShorten").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitOidShorten::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitOidShorten cannot be instantiated.");
     }

    GitOidShorten* object = new GitOidShorten(static_cast<git_oid_shorten *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitOidShorten::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitOidShorten::constructor_template), 2, argv).ToLocalChecked());
  }

  git_oid_shorten *GitOidShorten::GetValue() {
    return this->raw;
  }

  git_oid_shorten **GitOidShorten::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitOidShorten::ClearValue() {
    this->raw = NULL;
  }

     Nan::Persistent<Function> GitOidShorten::constructor_template;
 