#include "Test.h"
#include <assert.h>
#include "expect.h"
int Test::id(int t) { return ui.id((Amtui::tab_cycler)t); }
int testid(int v) {
    Test t;
    t.testuifid_conf();
    return t.id(v);
}
bool Test::getOk() { return ok; }
bool testcback() {
    Test t;
    t.testcycleback();
    return t.getOk();
}

void Test::testcycleback() {
    try { //try-catch block = exception handling
        ui.cycleback();
        ok = true;
    }
    catch (AssertErr) {
        ok = false;
    }
}
bool testlogin() {
    Test t;
    t.testLogin();
    return t.getOk();
}
bool testverifylogin() {
    Test t;
    t.testVerifyLogin();
    return t.getOk();
}
bool testverifypasslen() {
    Test t;
    t.testVerifyPasswordLength();
    return t.getOk();
}
void Test::testLogin() {
    ui.Manager::Login();
    StatusCode sc = ui.session.getStatusCode();
    if (sc == StatusCode::LoginErrorSession || sc == StatusCode::UserSession)
        ok = true;
    else
        ok = false;
}
void Test::testVerifyLogin() {
    ui.session.user.Email = "hello@manager.auth";
    ui.session.user.Password = "world";
    ui.session.ValidateUser();
    StatusCode sc = ui.session.getStatusCode();
    if (sc == StatusCode::UserSession)
        ok = true;
    else
        ok = false;
}
void Test::testVerifyLogin2() {
    describe("testVerifyLogin2()", [] {
        describe("test Session::Verify", [] {
            it("should return either usersession ", [] {
                expect(testverifylogin()).toBe(true);
                });
            });
        });
}
void Test::testVerifyPasswordLength2() {
    describe("testVerifyPasswordLength2()", [] {
        describe("test Session::VerifyPasswordLength", [] {
            it("should return true if passw length less than 5 chars ", [] {
                expect(testverifypasslen()).toBe(true);
                });
            });
        });
}
void Test::testVerifyPasswordLength() {
    ui.session.user.Email = "hello2@manager.auth";
    ui.session.user.Password = "world2";
    ok = ui.session.ValidatePasswordLength();
}

void Test::testcycleback2() {
    describe("testcycleback2()", [] {
        // xdescribe("skip me", [] {});
        // xit("skip me too");
        describe("amtui cycleback func", [] {
            it("should check cyccleback ok", [] {
                expect(testcback()).toBe(true);
                });
            });

        });
}
void Test::testLogin2() {
    describe("testLogin2()", [] {
        describe("test Manager::Login", [] {
            it("should return either usersession or errorsession", [] {
                expect(testlogin()).toBe(true);
                });
            });
        });
}
void Test::testuifid_conf() {
    ui.session.setStatus(LoginSession);
    Point2D tmp[] = { Point2D(7,21),Point2D(10,21)
                    ,Point2D(4,15),Point2D(4,35)
    };
    Amtui::tab_cycler t2[] = { Amtui::pbx,Amtui::ebx,Amtui::obx,Amtui::cbx };
    ui.configure(tmp, t2, (sizeof(t2) / sizeof(t2[0])));

}
void Test::testuifid() {
    describe("testuifid()", [] {
        // xdescribe("skip me", [] {});
        // xit("skip me too");
        describe("amtui find field index", [] {
            it("should check that id(field) returns correct index", [] {
                expect(testid(Amtui::ebx)).toBe(1);
                expect(testid(Amtui::pbx)).toBe(0);
                });
            });

        });

}
bool Test::testValidateVerifyPassword(string a,string b) {
    ui.session.user.PasswordVerify = a;
    ui.session.user.Password = b;
    return ui.session.ValidateVerifyPassword();
}
bool test_verifyValidatePassword(string a,string b) {
    Test t;
    return t.testValidateVerifyPassword(a, b);
}
void Test::testall() {
    //testcycleback2();
    //testuifid();
    //testLogin2();
    //testVerifyLogin2();
    //testVerifyPasswordLength2();
    describe("Yousuf Tests", [] {
        describe("test ValidateVerifyPassword()", [] {
            it("should return that user.password==user.verifyPassword", [] {
                expect(test_verifyValidatePassword("ok","ok")).toBe(true);
            });
        });
    });
    testSummary();
}
