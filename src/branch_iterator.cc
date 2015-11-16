// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/branch_iterator.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitBranchIterator::GitBranchIterator(git_branch_iterator *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitBranchIterator::~GitBranchIterator() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitBranchIterator::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("BranchIterator").ToLocalChecked());

  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("BranchIterator").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitBranchIterator::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitBranchIterator cannot be instantiated.");
     }

    GitBranchIterator* object = new GitBranchIterator(static_cast<git_branch_iterator *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitBranchIterator::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitBranchIterator::constructor_template), 2, argv).ToLocalChecked());
  }

  git_branch_iterator *GitBranchIterator::GetValue() {
    return this->raw;
  }

  git_branch_iterator **GitBranchIterator::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitBranchIterator::ClearValue() {
    this->raw = NULL;
  }

     Nan::Persistent<Function> GitBranchIterator::constructor_template;
 