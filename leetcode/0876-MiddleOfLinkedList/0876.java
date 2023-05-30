/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        // System.out.print(head.toString());
        // return head;
        ListNode ptr = head;
        int counter = 0;
        while (ptr.next != null) {
            ptr = ptr.next;
            counter++;
        }

        int mid = 0;
        if (counter % 2 == 0) {
            mid = counter / 2;
        }
        else {
            mid = counter / 2 + 1;
        }
        
        ptr = head;
        while (mid > 0) {
            ptr = ptr.next;
            mid--;
        }

        return ptr;
    }
}