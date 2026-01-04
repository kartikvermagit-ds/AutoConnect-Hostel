document.getElementById("save").onclick = () => {
  console.log("Save button clicked"); // 👈 Debug log
  const username = document.getElementById("username").value;
  const password = document.getElementById("password").value;
  chrome.storage.local.set({ username, password }, () => {
    console.log("Credentials saved to storage"); // 👈 Debug log
    alert("Credentials saved!");
  });
};

document.getElementById("connect").onclick = () => {
  console.log("Connect button clicked"); // 👈 Debug log
  chrome.tabs.create({ url: "https://192.168.1.2:8090/httpclient.html" });
};