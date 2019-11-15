import { requestApi } from './services/api/todo';

// Ask the server for saved todos
async function showTodos() {
  try{
    const res = await requestApi({ action: "GetTodos" });
    const data = await res.json();
  
    const list = document.getElementById("myUL");
  
    data.forEach(element => {
      const item = document.createElement("li");
      item.innerHTML = element
      list.appendChild(item);
    });
  }catch(error){
    console.log(error);
  }
  
};


//Add a todo in the server
async function showTodos() {
  const message = document.getElementById("feedback");

  try {
    const res = await requestApi({ action: "AddTodo" });
    const data = await res.json();
    message.innerHTML = "Added todo";
    console.log("Added todo");
  }catch(error) {
    console.log(error);
    message.innerHTML = "The todo was not added. Try it again later";
  }

};


// Create a "close" button and append it to each list item
var myNodelist = document.getElementsByTagName("LI");
var i;
for (i = 0; i < myNodelist.length; i++) {
  var span = document.createElement("SPAN");
  var txt = document.createTextNode("\u00D7");
  span.className = "close";
  span.appendChild(txt);
  myNodelist[i].appendChild(span);
}

// Click on a close button to hide the current list item
var close = document.getElementsByClassName("close");
var i;
for (i = 0; i < close.length; i++) {
  close[i].onclick = function () {
    var div = this.parentElement;
    div.style.display = "none";
  }
}

// Add a "checked" symbol when clicking on a list item
var list = document.querySelector('ul');
list.addEventListener('click', function (ev) {
  if (ev.target.tagName === 'LI') {
    ev.target.classList.toggle('checked');
  }
}, false);

// Create a new list item when clicking on the "Add" button
function newElement() {
  var li = document.createElement("li");
  var inputValue = document.getElementById("myInput").value;
  var t = document.createTextNode(inputValue);
  li.appendChild(t);
  if (inputValue === '') {
    alert("Tenes que ingresar datos!");
  } else {
    document.getElementById("myUL").appendChild(li);
  }
  document.getElementById("myInput").value = "";

  var span = document.createElement("SPAN");
  var txt = document.createTextNode("\u00D7");
  span.className = "close";
  span.appendChild(txt);
  li.appendChild(span);

  for (i = 0; i < close.length; i++) {
    close[i].onclick = function () {
      var div = this.parentElement;
      div.style.display = "none";
    }
  }
}