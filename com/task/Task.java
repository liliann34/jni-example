package com.task;

public class Task {
	private int id;
	private String desc;
	private TaskType taskType;

	public void setId(int id) { this.id = id; }
	public void setDesc(String desc) { this.desc = desc; }
	public String getDesc() {return this.desc; }

	public String toString() {
		return "{ id: " + id + ", " + "desc: " + desc + ", taskType: " + taskType.name() + "}";
	}
}
