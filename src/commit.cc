// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/commit.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
  #include "../include/signature.h"
  #include "../include/tree.h"
  #include "../include/repository.h"
  #include "../include/buf.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCommit::GitCommit(git_commit *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCommit::~GitCommit() {
      if (this->selfFreeing) {
        git_commit_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                }

  void GitCommit::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Commit").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "amend", Amend);
            Nan::SetPrototypeMethod(tpl, "author", Author);
            Nan::SetPrototypeMethod(tpl, "committer", Committer);
             Nan::SetMethod(tpl, "create", Create);
             Nan::SetMethod(tpl, "createV", CreateV);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "headerField", HeaderField);
            Nan::SetPrototypeMethod(tpl, "id", Id);
             Nan::SetMethod(tpl, "lookup", Lookup);
             Nan::SetMethod(tpl, "lookupPrefix", LookupPrefix);
            Nan::SetPrototypeMethod(tpl, "message", Message);
            Nan::SetPrototypeMethod(tpl, "messageEncoding", MessageEncoding);
            Nan::SetPrototypeMethod(tpl, "messageRaw", MessageRaw);
            Nan::SetPrototypeMethod(tpl, "nthGenAncestor", NthGenAncestor);
            Nan::SetPrototypeMethod(tpl, "owner", Owner);
            Nan::SetPrototypeMethod(tpl, "parent", Parent);
            Nan::SetPrototypeMethod(tpl, "parentId", ParentId);
            Nan::SetPrototypeMethod(tpl, "parentcount", Parentcount);
            Nan::SetPrototypeMethod(tpl, "rawHeader", RawHeader);
            Nan::SetPrototypeMethod(tpl, "summary", Summary);
            Nan::SetPrototypeMethod(tpl, "time", Time);
            Nan::SetPrototypeMethod(tpl, "timeOffset", TimeOffset);
            Nan::SetPrototypeMethod(tpl, "tree", Tree);
            Nan::SetPrototypeMethod(tpl, "treeId", TreeId);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Commit").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCommit::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCommit cannot be instantiated.");
     }

    GitCommit* object = new GitCommit(static_cast<git_commit *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCommit::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCommit::constructor_template), 2, argv).ToLocalChecked());
  }

  git_commit *GitCommit::GetValue() {
    return this->raw;
  }

  git_commit **GitCommit::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCommit::ClearValue() {
    this->raw = NULL;
  }

  
/*
    * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
     * @return Oid id    */
NAN_METHOD(GitCommit::Amend) {
  Nan::EscapableHandleScope scope;

  git_oid *id = (git_oid *)malloc(sizeof(git_oid));
// start convert_from_v8 block
  const char * from_update_ref;
    if (info[0]->IsString()) {

  String::Utf8Value update_ref(info[0]->ToString());
  from_update_ref = (const char *) strdup(*update_ref);
  }
  else {
    from_update_ref = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_author;
    if (info[1]->IsObject()) {
  from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[1]->ToObject())->GetValue();
  }
  else {
    from_author = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer;
    if (info[2]->IsObject()) {
  from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[2]->ToObject())->GetValue();
  }
  else {
    from_committer = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message_encoding;
    if (info[3]->IsString()) {

  String::Utf8Value message_encoding(info[3]->ToString());
  from_message_encoding = (const char *) strdup(*message_encoding);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message;
    if (info[4]->IsString()) {

  String::Utf8Value message(info[4]->ToString());
  from_message = (const char *) strdup(*message);
  }
  else {
    from_message = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree * from_tree;
    if (info[5]->IsObject()) {
  from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[5]->ToObject())->GetValue();
  }
  else {
    from_tree = 0;
  }
// end convert_from_v8 block
   int result = git_commit_amend(
id
,Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
,from_update_ref
,from_author
,from_committer
,from_message_encoding
,from_message
,from_tree
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (id != NULL) {
    // GitOid id
       to = GitOid::New((void *)id, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Signature  result    */
NAN_METHOD(GitCommit::Author) {
  Nan::EscapableHandleScope scope;

   const git_signature * result = git_commit_author(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitSignature result
       to = GitSignature::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Signature  result    */
NAN_METHOD(GitCommit::Committer) {
  Nan::EscapableHandleScope scope;

   const git_signature * result = git_commit_committer(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitSignature result
       to = GitSignature::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param Repository repo
   * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
   * @param Number parent_count
   * @param Array parents
     * @return Oid id    */
NAN_METHOD(GitCommit::Create) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Signature author is required.");
  }

  if (info.Length() == 3 || !info[3]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  if (info.Length() == 5 || !info[5]->IsString()) {
    return Nan::ThrowError("String message is required.");
  }

  if (info.Length() == 6 || !info[6]->IsObject()) {
    return Nan::ThrowError("Tree tree is required.");
  }

  if (info.Length() == 7 || !info[7]->IsNumber()) {
    return Nan::ThrowError("Number parent_count is required.");
  }

  if (info.Length() == 8 || !info[8]->IsObject()) {
    return Nan::ThrowError("Array parents is required.");
  }

  git_oid *id = (git_oid *)malloc(sizeof(git_oid));
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_update_ref;
    if (info[1]->IsString()) {

  String::Utf8Value update_ref(info[1]->ToString());
  from_update_ref = (const char *) strdup(*update_ref);
  }
  else {
    from_update_ref = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_author;
  from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer;
  from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[3]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message_encoding;
    if (info[4]->IsString()) {

  String::Utf8Value message_encoding(info[4]->ToString());
  from_message_encoding = (const char *) strdup(*message_encoding);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message;

  String::Utf8Value message(info[5]->ToString());
  from_message = (const char *) strdup(*message);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree * from_tree;
  from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[6]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_parent_count;
  from_parent_count = (size_t)   info[7]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_commit ** from_parents;

  Array *tmp_parents = Array::Cast(*info[8]);
  from_parents = (const git_commit **)malloc(tmp_parents->Length() * sizeof(const git_commit *));
      for (unsigned int i = 0; i < tmp_parents->Length(); i++) {
      from_parents[i] = Nan::ObjectWrap::Unwrap<GitCommit>(tmp_parents->Get(Nan::New(static_cast<double>(i)))->ToObject())->GetValue();
      }
// end convert_from_v8 block
   int result = git_commit_create(
id
,from_repo
,from_update_ref
,from_author
,from_committer
,from_message_encoding
,from_message
,from_tree
,from_parent_count
,from_parents
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (id != NULL) {
    // GitOid id
       to = GitOid::New((void *)id, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Oid id
   * @param Repository repo
   * @param String update_ref
   * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
   * @param Tree tree
   * @param Number parent_count
     * @return Number  result    */
NAN_METHOD(GitCommit::CreateV) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String update_ref is required.");
  }

  if (info.Length() == 3 || !info[3]->IsObject()) {
    return Nan::ThrowError("Signature author is required.");
  }

  if (info.Length() == 4 || !info[4]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  if (info.Length() == 5 || !info[5]->IsString()) {
    return Nan::ThrowError("String message_encoding is required.");
  }

  if (info.Length() == 6 || !info[6]->IsString()) {
    return Nan::ThrowError("String message is required.");
  }

  if (info.Length() == 7 || !info[7]->IsObject()) {
    return Nan::ThrowError("Tree tree is required.");
  }

  if (info.Length() == 8 || !info[8]->IsNumber()) {
    return Nan::ThrowError("Number parent_count is required.");
  }

// start convert_from_v8 block
  git_oid * from_id;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_update_ref;

  String::Utf8Value update_ref(info[2]->ToString());
  from_update_ref = (const char *) strdup(*update_ref);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_author;
  from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[3]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer;
  from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[4]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message_encoding;

  String::Utf8Value message_encoding(info[5]->ToString());
  from_message_encoding = (const char *) strdup(*message_encoding);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message;

  String::Utf8Value message(info[6]->ToString());
  from_message = (const char *) strdup(*message);
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree * from_tree;
  from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[7]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_parent_count;
  from_parent_count = (size_t)   info[8]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_commit_create_v(
from_id
,from_repo
,from_update_ref
,from_author
,from_committer
,from_message_encoding
,from_message
,from_tree
,from_parent_count
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitCommit::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue() != NULL) {
 git_commit_free(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
  
/*
    * @param String field
    * @param Buf callback
   */
NAN_METHOD(GitCommit::HeaderField) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String field is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  HeaderFieldBaton* baton = new HeaderFieldBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));;
      baton->out->ptr = NULL;
      baton->out->size = baton->out->asize = 0;
  baton->commit = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_field;

  String::Utf8Value field(info[0]->ToString());
  from_field = (const char *) strdup(*field);
// end convert_from_v8 block
  baton->field = from_field;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  HeaderFieldWorker *worker = new HeaderFieldWorker(baton, callback);
  worker->SaveToPersistent("commit", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("field", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCommit::HeaderFieldWorker::Execute() {
  int result = git_commit_header_field(
baton->out,baton->commit,baton->field    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCommit::HeaderFieldWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->out) {
    to = Nan::New<String>(baton->out->ptr, baton->out->size).ToLocalChecked();
  }
  else {
    to = Nan::Null();
  }
 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("field"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method headerField has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  git_buf_free(baton->out);
  free((void *)baton->out);
  free((void *)baton->field);

  delete baton;
}

   
/*
     * @return Oid  result    */
NAN_METHOD(GitCommit::Id) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_commit_id(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
  
/*
  * @param Repository repo
   * @param Oid id
    * @param Commit callback
   */
NAN_METHOD(GitCommit::Lookup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupBaton* baton = new LookupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[1]->IsString();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  LookupWorker *worker = new LookupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCommit::LookupWorker::Execute() {
  int result = git_commit_lookup(
&baton->commit,baton->repo,baton->id    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCommit::LookupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->commit != NULL) {
    // GitCommit baton->commit
       to = GitCommit::New((void *)baton->commit, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("id"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method lookup has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Oid id
   * @param Number len
    * @param Commit callback
   */
NAN_METHOD(GitCommit::LookupPrefix) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number len is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupPrefixBaton* baton = new LookupPrefixBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[1]->IsString();
// start convert_from_v8 block
  size_t from_len;
  from_len = (size_t)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->len = from_len;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  LookupPrefixWorker *worker = new LookupPrefixWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("len", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCommit::LookupPrefixWorker::Execute() {
  int result = git_commit_lookup_prefix(
&baton->commit,baton->repo,baton->id,baton->len    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCommit::LookupPrefixWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->commit != NULL) {
    // GitCommit baton->commit
       to = GitCommit::New((void *)baton->commit, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("id"));
      workerArguments.push(GetFromPersistent("len"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method lookupPrefix has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

   
/*
     * @return String  result    */
NAN_METHOD(GitCommit::Message) {
  Nan::EscapableHandleScope scope;

   const char * result = git_commit_message(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitCommit::MessageEncoding) {
  Nan::EscapableHandleScope scope;

   const char * result = git_commit_message_encoding(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitCommit::MessageRaw) {
  Nan::EscapableHandleScope scope;

   const char * result = git_commit_message_raw(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
    * @param Number n
    * @param Commit callback
   */
NAN_METHOD(GitCommit::NthGenAncestor) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  NthGenAncestorBaton* baton = new NthGenAncestorBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->commit = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();
// start convert_from_v8 block
  unsigned int from_n;
  from_n = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->n = from_n;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  NthGenAncestorWorker *worker = new NthGenAncestorWorker(baton, callback);
  worker->SaveToPersistent("commit", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("n", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCommit::NthGenAncestorWorker::Execute() {
  int result = git_commit_nth_gen_ancestor(
&baton->ancestor,baton->commit,baton->n    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCommit::NthGenAncestorWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->ancestor != NULL) {
    // GitCommit baton->ancestor
       to = GitCommit::New((void *)baton->ancestor, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("n"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method nthGenAncestor has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
     * @return Repository  result    */
NAN_METHOD(GitCommit::Owner) {
  Nan::EscapableHandleScope scope;

   git_repository * result = git_commit_owner(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitRepository result
       to = GitRepository::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
    * @param Number n
    * @param Commit callback
   */
NAN_METHOD(GitCommit::Parent) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ParentBaton* baton = new ParentBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->commit = Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue();
// start convert_from_v8 block
  unsigned int from_n;
  from_n = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->n = from_n;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  ParentWorker *worker = new ParentWorker(baton, callback);
  worker->SaveToPersistent("commit", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("n", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCommit::ParentWorker::Execute() {
  int result = git_commit_parent(
&baton->out,baton->commit,baton->n    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCommit::ParentWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitCommit baton->out
       to = GitCommit::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("n"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method parent has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
   * @param Number n
     * @return Oid  result    */
NAN_METHOD(GitCommit::ParentId) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

// start convert_from_v8 block
  unsigned int from_n;
  from_n = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   const git_oid * result = git_commit_parent_id(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
,from_n
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
   
/*
     * @return Number  result    */
NAN_METHOD(GitCommit::Parentcount) {
  Nan::EscapableHandleScope scope;

   unsigned int result = git_commit_parentcount(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitCommit::RawHeader) {
  Nan::EscapableHandleScope scope;

   const char * result = git_commit_raw_header(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitCommit::Summary) {
  Nan::EscapableHandleScope scope;

   const char * result = git_commit_summary(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitCommit::Time) {
  Nan::EscapableHandleScope scope;

   git_time_t result = git_commit_time(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitCommit::TimeOffset) {
  Nan::EscapableHandleScope scope;

   int result = git_commit_time_offset(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Tree tree_out
       * @return Number  result    */
NAN_METHOD(GitCommit::Tree) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Tree tree_out is required.");
  }

// start convert_from_v8 block
  git_tree ** from_tree_out;
  from_tree_out = Nan::ObjectWrap::Unwrap<GitTree>(info[0]->ToObject())->GetRefValue();
// end convert_from_v8 block
   int result = git_commit_tree(
from_tree_out
,Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitCommit::TreeId) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_commit_tree_id(
Nan::ObjectWrap::Unwrap<GitCommit>(info.This())->GetValue()
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
      Nan::Persistent<Function> GitCommit::constructor_template;
 