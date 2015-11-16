#ifndef GITDESCRIBEFORMATOPTIONS_H
#define GITDESCRIBEFORMATOPTIONS_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitDescribeFormatOptions : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_describe_format_options *GetValue();
    git_describe_format_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDescribeFormatOptions(git_describe_format_options *raw, bool selfFreeing);
    ~GitDescribeFormatOptions();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Version);
    static NAN_METHOD(AbbreviatedSize);
    static NAN_METHOD(AlwaysUseLongFormat);
    static NAN_METHOD(DirtySuffix);
    git_describe_format_options *raw;
};

#endif
