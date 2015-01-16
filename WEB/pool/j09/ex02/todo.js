var tmp;
var taskArray = document.cookie.split(";");
console.log(taskArray);
var count = taskArray.length;

function deleteRow()
{
    var answer = confirm("Are you sure you want to delete this task?");
    if (answer)
    {
        document.cookie = this.id + "=; ";
        this.parentNode.removeChild(this);
    }
}

function createTask(todo, val) {
    var task = document.createElement("div");
    task.innerHTML = todo;
    task.onclick = deleteRow;
    task.id = val;
    var list = document.getElementById("ft_list");
    list.insertBefore(task, list.firstChild);
}

function newTask() {
    var todo = window.prompt("New");
    document.cookie = count + "=" + encodeURIComponent(todo);
    createTask(todo, count);
    count++;
}

function cookInit() {
    var i = 0;
    var str;
    var key;
    while (i < count)
    {
        if (taskArray[i] == "")
        {
            count = 0;
            return ;
        }
        str = taskArray[i].replace(/.*=/, "");
        key = taskArray[i].replace(/=.*/, "");
        if (str != "")
            createTask(decodeURIComponent(str), key);
        i++;
    }
}