/*
 * intro.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: lewiatan
 */

#include <Wt/WApplication>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WBreak>
// c++0x only, for std::bind
#include <functional>

class OurApp : public Wt::WApplication
{
public:
  OurApp(const Wt::WEnvironment& env);

private:
  Wt::WLineEdit* nameEdit;
  Wt::WText* outputText;
};

OurApp::OurApp(const Wt::WEnvironment& env)
  : Wt::WApplication(env)
{
  setTitle("Hello world");

  root()->addWidget(new Wt::WText("Your name, please ? "));
  nameEdit = new Wt::WLineEdit(root());
  nameEdit->setFocus();

  Wt::WPushButton* button
    = new Wt::WPushButton("Greet me.", root());
  button->setMargin(5, Wt::Left);
  root()->addWidget(new Wt::WBreak());

  outputText = new Wt::WText(root());

//  for different style (without lambdas)- write method greet()
//  and connect it as below:
//  button->clicked().connect(this, &OurApp::greet);
  button->clicked().connect(std::bind([=]() {
      outputText->setText("Hello there, " + nameEdit->text());
  }));
}

Wt::WApplication* startApp(const Wt::WEnvironment& env)
{
  return new OurApp(env);
}

int main(int argc, char* argv[])
{
    return WRun(argc, argv, &startApp);
}
