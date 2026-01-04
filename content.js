chrome.storage.local.get(["username", "password"], (data) => {
  const usernameField = document.getElementById("username");
  const passwordField = document.getElementById("password");

  if (usernameField && passwordField) {
    usernameField.value = data.username;
    passwordField.value = data.password;

    // Try clicking the login button instead of form.submit()
    const loginButton = document.querySelector("input[type='submit'], button[type='submit']");
    if (loginButton) {
      loginButton.click();
    } else {
      console.error("Login button not found!");
    }
  }
});