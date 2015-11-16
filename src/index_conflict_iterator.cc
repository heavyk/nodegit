// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/index_conflict_iterator.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitIndexConflictIterator::GitIndexConflictIterator(git_index_conflict_iterator *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitIndexConflictIterator::~GitIndexConflictIterator() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitIndexConflictIterator::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("IndexConflictIterator").ToLocalChecked());

  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("IndexConflictIterator").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitIndexConflictIterator::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitIndexConflictIterator cannot be instantiated.");
     }

    GitIndexConflictIterator* object = new GitIndexConflictIterator(static_cast<git_index_conflict_iterator *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitIndexConflictIterator::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitIndexConflictIterator::constructor_template), 2, argv).ToLocalChecked());
  }

  git_index_conflict_iterator *GitIndexConflictIterator::GetValue() {
    return this->raw;
  }

  git_index_conflict_iterator **GitIndexConflictIterator::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitIndexConflictIterator::ClearValue() {
    this->raw = NULL;
  }

     Nan::Persistent<Function> GitIndexConflictIterator::constructor_template;
 