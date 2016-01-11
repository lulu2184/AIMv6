diskutil unmount /Volumes/KERNEL
diskutil unmount /Volumes/BOARD
diskutil unmount /Volumes/P0
sudo dd if=kern/kern.elf of=/dev/disk2s2
sudo dd if=mbr.bin of=/dev/disk2 count=1 bs=446
sudo dd if=user/prog1.elf of=/dev/disk2s3
sync
diskutil unmount /Volumes/KERN
diskutil unmount /Volumes/BOARD
diskutil unmount /Volumes/P0

