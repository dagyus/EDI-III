<<<<<<< HEAD
import { requestApi } from './services/api/todo';

async function showTodos() {
  try {
    const res = await requestApi({ action: "ReadNotes" });
    const data = await res.json();

    const list = document.getElementById("myUL");

    data.forEach(element => {
      const item = document.createElement("li");
      item.innerHTML = `
        <p>
          ${element.value}
        </p> 
        <button onclick="updateTodo(${element.id})" > editar </button>
        <button onclick="deleteTodo(${element.id})"> eliminar </button>
      `
      list.appendChild(item);
    });
  } catch (error) {
    console.log(error);
  }
};


//Add a todo in the server
async function showTodos() {
  const message = document.getElementById("feedback");
  const { value } = document.getElementById("myInput");
  try {
    const res = await requestApi({ action: "CreateNote", value });
    const data = await res.json();
    message.innerHTML = "Added todo";
    console.log("Added todo");
  } catch (error) {
    console.log(error);
    message.innerHTML = "The todo was not added. Try it again later";
  }
};


async function updateTodo(id){
  const message = document.getElementById("feedback");
  try {
    const value = prompt("Ingrese el nuevo valor");
    const res = await requestApi({ action: "UupdateNote", id, value });
    const data = await res.json();
    message.innerHTML = "Ypdated todo";
  } catch (error) {
    message.innerHTML = "The todo was not added. Try it again later";
  }
}

async function deleteTodo(id){
  const message = document.getElementById("feedback");
  try {
    const res = await requestApi({ action: "DeleteNote", id });
    const data = await res.json();
    message.innerHTML = "Deleted todo";
  } catch (error) {
    message.innerHTML = "The todo was not added. Try it again later";
  }
}

=======
>>>>>>> 1f1db33841b56a72d980ce67f2044f158f12a59b
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
  close[i].onclick = function() {
    var div = this.parentElement;
    div.style.display = "none";
  }
}

// Add a "checked" symbol when clicking on a list item
var list = document.querySelector('ul');
list.addEventListener('click', function(ev) {
  if (ev.target.tagName === 'LI') {
    ev.target.classList.toggle('checked');
  }
}, false);

// Create a new list item when clicking on the "Add" button
function newElement(event) {
  debugger;
  if (event.keyCode === 13  || event.type === "click") {
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
      close[i].onclick = function() {
        var div = this.parentElement;
        div.style.display = "none";
      }
    }
  }
 
}